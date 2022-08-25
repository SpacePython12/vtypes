build/libvtypes.a: build/vbuffer.o
	mkdir -p build
	gcc -fPIC -o $@ $^ -Iinclude -shared

build/%.o: src/%.c
	mkdir -p build
	gcc -c $^ -o $@ -Iinclude

test: build/libvtypes.a
	mkdir -p build
	gcc test/testvbuffer.c -o build/test -Iinclude -Lbuild -lvtypes 
	build/test

clean:
	rm -f build/*