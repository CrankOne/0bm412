
# Common variables
CFLAGS:=-Iinclude
CC:=g++

# What to do, if no target was explicitly specified (e.g., just `make` was ran)
all: accept-reject \
	 inverse-function \
	 kahan-sum \
	 g4-app

#
# Common template rules

# Rule to produce .o files from .c (pure C) files in src/
obj/%.o: src/%.c
	$(CC) -c -x c $(CFLAGS) $< -o $@

# Rule to produce .o files from .c (pure C) files in current dir
obj/main.%.o: main.%.c
	$(CC) -c -x c $(CFLAGS) $< -o $@

# Rule to produce .o files from .cc (C++) files in src/
obj/%.o: src/%.cc
	g++ -c $(CFLAGS) $< -o $@

# Rule to produce .o files from main.*.cc (C++) files in current dir
obj/main.%.o: main.%.cc
	g++ -c $(CFLAGS) $< -o $@

obj/main.geant4.o: main.geant4.cc
	g++ -c $(CFLAGS) $(shell geant4-config --cflags) $< -o $@

# Rule to produce .o files from g4/*.cc (C++) files in src/
obj/g4-%.o: src/g4/%.cc
	g++ -c $(shell geant4-config --cflags) $(CFLAGS) $< -o $@

#
# Project main targets

# Static library target:
lib0bm412.a: obj/histogram1d.o \
			 obj/accept-reject.o \
			 obj/kahan.o
	ar -crs $@ $^

# testing executable for accept-reject method
accept-reject: obj/main.accept-reject.o lib0bm412.a
	$(CC) $< -L. -l0bm412 -lm -o $@

# testing executable for inverse-function method
inverse-function: obj/main.inverse-function.o lib0bm412.a
	$(CC) $< -L. -l0bm412 -lm -o $@

# testing executable for kahan summator
kahan-sum: obj/main.kahan.o lib0bm412.a
	$(CC) $< -L. -l0bm412 -lm -o $@

# Geant4 application
g4-app: obj/g4-PrimaryGeneratorAction.o \
		obj/g4-DetectorConstruction.o \
		obj/g4-ActionInitialization.o \
		obj/g4-SensitiveDetector.o \
		obj/main.geant4.o
	$(CC) $^ -L. $(shell geant4-config --libs) \
		-Wl,--disable-new-dtags,-rpath=$(shell geant4-config --prefix)/lib -o $@

#
# Aux targets

clean:
	@rm -fv obj/*.o
	@rm -fv lib0bm412.a
	@rm -fv accept-reject inverse-function kahan-sum

.PHONY: all clean
