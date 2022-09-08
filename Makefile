build/libvtypes.a: build/varray.o build/vmap.o build/vutil.o
	mkdir -p build
	gcc -Wall -fPIC -o $@ $^ -Iinclude -shared -g

build/%.o: src/%.c
	mkdir -p build
	gcc -Wall -c $^ -o $@ -Iinclude -g

test: build/libvtypes.a
	mkdir -p build
	gcc -Wall test/testvmap.c -o build/test -Iinclude -Lbuild -lvtypes -g
	build/test

clean:
	rm -f build/*