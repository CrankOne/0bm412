
CFLAGS:=-x c -c -Iinclude

all: accept-reject \
	 inverse-function

%.o: src/%.c
	gcc $(CFLAGS) $< -o $@

%.main.o: src/%.main.c
	gcc $(CFLAGS) $< -o $@

main.o: main.c
	gcc $(CFLAGS) $< -o $@

accept-reject: accept-reject.main.o \
			   histogram1d.o \
			   accept-reject.o
	gcc $^ -lm -o $@

inverse-function: inverse-function.main.o \
				  histogram1d.o
	gcc $^ -lm -o $@

clean:
	rm -fv *.o
	rm -fv accept-reject inverse-function

