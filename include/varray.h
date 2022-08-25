#ifndef _VARRAY_H_
#define _VARRAY_H_ 1

#ifndef _STDLIB_H_ 
#include <stdlib.h>
#endif

typedef struct varray_t {
    void * data;
    size_t nblocks;
    size_t blocksize;
} varray_t;

#ifdef __cplusplus
extern "C" {
#endif

// Allocate a new varray. The caller is responsible for freeing this structure.
varray_t * varray_new(size_t blocksize, size_t nblocks);
// Allocate a new varray, and initialize it with DATA. The caller is responsible for freeing this structure.
varray_t * varray_from(void * data, size_t blocksize, size_t nblocks);
// Free this varray.
void varray_free(varray_t * vl);

// Returns the number of elements in the list.
size_t varray_length(varray_t * vl);
// Returns the element size of the list.
size_t varray_elemsize(varray_t * vl);
// Returns the raw data of the list.
void * varray_data(varray_t * vl)



#ifdef __cplusplus
}
#endif

#endif