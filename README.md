# VTypes

VTypes is a C/C++ library for dynamic collection types, aiming to be memory safe, compact, and fast. It takes inspiration from the Java standard library, and aims to have a similar interface.
## Features:
* An array type, with a data pointer and size values.
    * A list interface, with insertion/deletion methods.
    * A stack interface, with push, pop, and peek.
    * A queue interface, with add, remove, and peek.
    * A heap interface, with type get/put methods.
* A linked list interface, similar to the array but with linked lists.*
* A map and tree interface.*
* A string interface.*

<sub>* Not implemented yet.</sub>

# Installation:
* If you are on Windows, you MUST install MSYS2.
* Clone the repository using Git: `git clone https://github.com/SpacePython12/vtypes.git`.
* Run `make` in the project directory to build the library.
* The compiled library is in the `build` directory named `libvtypes.a`. Any headers you need are in the `include` directory.
* You can put the library in your project folder, and compile with `-lvtypes`.

# Usage: 
### vbuffer usage (outdated)
```c
// Optionally, include these before the vtypes headers for IO functions.
#include <stdio.h> // for FILE * operations
#include <unistd.h> // for fd operations

#include <vbuffer.h> // vbuffer
#include <vstring> // vstring

int main(int argc, char ** argv) {
    vbuffer_t * buf = vbuffer_new(16); // Initializes the vbuffer with 16 bytes of initial capacity
    vbuffer_put_uint32(buf, 0, 0x12345678); // Puts 0x12345678 at position 0 in the buffer.
    printf("%x\n", vbuffer_get_uint32(buf, 0)); // Retrieves the int we just stored.
    vbuffer_put_array(buf, 0, "This should overwrite the buffer!", 33); // Places this string in the buffer, but the buffer isn't big enough!
    vbuffer_resize(buf, 64); // Now it is!
    vbuffer_put_array(buf, 0, "This won't overwrite the buffer!", 32); // Now the string does fit!
    vbuffer_free(buf); // Don't forget to free  the buffer!
}
```

# Support / Contribute
**If you caught a bug, be sure to check out the [issues page](https://github.com/SpacePython12/vtypes/issues).**

Pull requests are welcome and encouraged.
When you contribute, do the following:
* Address any issues that this commit fixes
* If you change the code in any way, make sure to update the tests accordingly.