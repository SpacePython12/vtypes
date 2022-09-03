#include <stdio.h>
#include "varray.h"

int main() {
    char src[4] = {1, 2, 3, 4};
    varray(char) * array;
    varray_initfrom(array, &src, 4);
    varray_add(array, 5);
    printf("%d\n", varray_at(array, 5));
    varray_free(array);
}