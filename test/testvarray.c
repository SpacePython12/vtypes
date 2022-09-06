#include <stdio.h>
#include "varray.h"
#include "vlist.h"

int main() {
    char src[4] = {1, 2, 3, 4};
    varray(char) * array;
    varray_free(array);
}