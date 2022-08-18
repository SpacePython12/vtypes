#ifndef _VLIST_H_
#define _VLIST_H_ 1

#ifndef _STDLIB_H_ 
#include <stdlib.h>
#endif

typedef struct vlist_t {
    void * data;
    size_t nblocks;
    size_t blocksize;
} vlist_t;

#ifdef __cplusplus
extern "C" {
#endif

// Allocate a new vlist. The caller is responsible for freeing this structure.
vlist_t * vlist_new(size_t blocksize, size_t nblocks);
// Allocate a new vlist, and initialize it with DATA. The caller is responsible for freeing this structure.
vlist_t * vlist_from(void * data, size_t blocksize, size_t nblocks);
// Free this vlist.
void vlist_free(vlist_t * vl);

// Returns the number of elements in the list.
size_t vlist_length(vlist_t * vl);
// Returns the element size of the list.
size_t vlist_elemsize(vlist_t * vl);
// Returns the raw data of the list.
void * vlist_data(vlist_t * vl)



#ifdef __cplusplus
}
#endif

#endif