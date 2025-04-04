
CFLAGS:=-x c -c -Iinclude

all: test-accept-reject

%.o: src/%.c
	gcc $(CFLAGS) $< -o $@

main.o: main.c
	gcc $(CFLAGS) $< -o $@

test-accept-reject: main.o \
					histogram1d.o \
					accept-reject.o
	gcc $^ -lm -o $@

clean:
	rm -fv *.o
	rm -fv test-accept-reject

