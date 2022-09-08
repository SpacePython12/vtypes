#ifndef _VMAP_H_
#define _VMAP_H_ 1

#include "varray.h"

#define IS_NULLTERM 0

typedef unsigned long vmap_key_t;

typedef struct vmap_pair_t {
    vmap_key_t keyhash;
    vague_t key;
    vague_t val;
} vmap_pair_t;

typedef struct vmap {
    varray arr;
    size_t ksize;
    size_t vsize;
} vmap;

typedef char * (*vmap_printpair_fn) (vague_t key, vague_t val);

// Macro containing the key size of the given map.
#define vmap_ksize(inst) ((inst)->ksize)
// Macro containing the value size of the given map.
#define vmap_vsize(inst) ((inst)->vsize)
// Macro containing the length of the given array. Don't write to this unless you know what you are doing.
#define vmap_len(inst) (varray_len(&(inst)->arr))

// Initialize the map with a given key size and value size. Use IS_NULLTERM instead of a type size to indicate null-terminated data.
extern inline vmap * vmap_init(size_t ksize, size_t vsize);
// Free the map.
extern inline void vmap_free(vmap * inst);
// Remove all the entries in this map.
extern inline void vmap_reset(vmap * inst);
// Add an entry to this map.
extern inline void vmap_add(vmap * inst, vague_t key, vague_t val);
// Remove an entry from this map.
extern inline void vmap_rem(vmap * inst, vague_t key);
// Find the internal index of the entry with the given key. Returns __SIZE_MAX__ if one was not found.
extern inline size_t vmap_find(vmap * inst, vague_t key);
// Gets the value of the entry with a given key. Returns NULL if it was not found.
extern inline vague_t vmap_get(vmap * inst, vague_t key);
// Gets the entry with the given key. Returns NULL if it was not found.
extern inline vmap_pair_t * vmap_getp(vmap * inst, vague_t key);
// Gets the entry at the given internal index. Returns NULL if the index is invalid.
extern inline vmap_pair_t * vmap_getp_at(vmap * inst, size_t index);
// Sets the value of the entry with a given key.
extern inline void vmap_set(vmap * inst, vague_t key, vague_t val);

extern char * vmap_print(vmap * inst, vmap_printpair_fn pfn);

extern inline void _vmap_pair_set(vmap_pair_t * pair, vague_t key, size_t ksize, vague_t val, size_t vsize);
extern inline void _vmap_pair_free(vmap_pair_t * pair);

#endif