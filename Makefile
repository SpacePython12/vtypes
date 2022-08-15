build/libvtypes.so: build/vbuffer.o
	gcc -fPIC -shared -o build/libvtypes.so build/vbuffer.o

build/%.o: src/%.c
	gcc -c src/%.c -o build/%.o