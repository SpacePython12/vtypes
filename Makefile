build/libvtypes.so: build/vbuffer.o
	mkdir -p build
	gcc -fPIC -o $@ $^ -Iinclude -shared

build/%.o: src/%.c
	mkdir -p build
	gcc -c $^ -o $@ -Iinclude

test: build/vbuffer.o
	mkdir -p build
	gcc test/testvbuffer.c -o build/test -Iinclude -static build/vbuffer.o -g
	build/test

clean:
	rm -f build/*