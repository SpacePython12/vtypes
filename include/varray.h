#ifndef _VARRAY_H_
#define _VARRAY_H_ 1

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

// An abstract list of a given type.
#define varray(T) struct varray_##T {T * data; size_t len;}

// Macro containing the type size (as by sizeof()) of the given array.
#define varray_tsize(arr) (sizeof(*(arr)->data))
// Macro containing the raw pointer to the data. Use this only if you know what you are doing.
#define varray_data(arr) ((arr)->data)
// Macro containing the value at the given index in the given array.
#define varray_at(arr, ind) ((arr)->data[ind])
// Macro containing the length of the array. Don't write to this unless you know what you are doing.
#define varray_len(arr) ((arr)->len)

// Initializes the given array with a valid data pointer and a given size.
#define varray_init(arr, len)\
{\
    arr = malloc(sizeof(void *) + sizeof(size_t));\
    varray_data(arr) = malloc(varray_tsize(arr) * len);\
    varray_len(arr) = len;\
}
// Initializes the given array with a valid data pointer and a given size, then copies data into it, without overflowing the allocated space.
#define varray_initfrom(arr, data, len)\
{\
    varray_init(arr, len);\
    memmove(varray_data(arr), data, varray_len(arr)*varray_tsize(arr));\
}
// Frees the given array.
#define varray_free(arr)\
{\
    free(varray_data(arr));\
    free(arr);\
}
// Resizes the given array to the given size.
#define varray_resize(arr, len)\
{\
    varray_data(arr) = realloc(varray_data(arr), len*varray_tsize(arr));\
    varray_len(arr) = len;\
}
// Inserts a given value at the given index.
#define varray_insert(arr, ind, val)\
{\
    varray_resize(arr, varray_len(arr)+1);\
    memmove(varray_data(arr)+(ind*varray_tsize(arr))+varray_tsize(arr), varray_data(arr)+(ind*varray_tsize(arr)), varray_len(arr)-ind);\
    varray_at(arr, ind) = val;\
}
// Removes the value at the given index.
#define varray_remove(arr, ind)\
{\
    memmove(varray_data(arr)+(ind*varray_tsize(arr))-varray_tsize(arr), varray_data(arr)+(ind*varray_tsize(arr)), varray_len(arr)-ind);\
    varray_resize(arr, varray_len(arr)-1);\
}
// Sets all of the members of the given array to NULL or 0.
#define varray_clear(arr)\
{\
    memset(varray_data(arr), 0, varray_len(arr)*varray_tsize(arr));\
}
// Sets the size of the given array to zero.
#define varray_reset(arr)\
{\
    varray_resize(arr, 0);\
}
// Insert a value at the end of the array.
#define varray_add(arr, val)\
{\
    varray_insert(arr, varray_len(arr), val);\
}

#endif