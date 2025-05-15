
# Common variables
CFLAGS:=-Iinclude

# What to do, if no target was explicitly specified (e.g., just `make` was ran)
all: accept-reject \
	 inverse-function \
	 kahan-sum

#
# Common template rules

# Rule to produce .o files from .c (pure C) files in src/
obj/%.o: src/%.c
	gcc -c -x c $(CFLAGS) $< -o $@

# Rule to produce .o files from .c (pure C) files in current dir
obj/main.%.o: main.%.c
	gcc -c -x c $(CFLAGS) $< -o $@

# Rule to produce .o files from .cc (C++) files in src/
obj/%.o: src/%.cc
	g++ -c $(CFLAGS) $< -o $@

# Rule to produce .o files from .c (C++) files in current dir
obj/main.%.o: main.%.cc
	g++ -c $(CFLAGS) $< -o $@

#
# Project main targets

# Static library target:
lib0bm412.a: obj/histogram1d.o \
			 obj/accept-reject.o \
			 obj/kahan.o
	ar -crs $@ $^

# testing executable for accept-reject method
accept-reject: obj/main.accept-reject.o lib0bm412.a
	gcc $< -L. -l0bm412 -lm -o $@

# testing executable for inverse-function method
inverse-function: obj/main.inverse-function.o lib0bm412.a
	gcc $< -L. -l0bm412 -lm -o $@

# testing executable for kahan summator
kahan-sum: obj/main.kahan.o lib0bm412.a
	gcc $< -L. -l0bm412 -lm -o $@

#
# Aux targets

clean:
	@rm -fv obj/*.o
	@rm -fv lib0bm412.a
	@rm -fv accept-reject inverse-function kahan-sum

.PHONY: all clean
