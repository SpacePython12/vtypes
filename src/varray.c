#include "varray.h"
#include "valist.h"
#include "vastack.h"
#include "vaqueue.h"

#include <string.h>

inline varray * varray_init(size_t esize, size_t len) {
    varray * inst = malloc(sizeof(void *) + sizeof(size_t) + sizeof(size_t));
    varray_esize(inst) = esize;
    varray_data(inst) = malloc(varray_esize(inst) * len);
    varray_len(inst) = len;
    return inst;
}

inline varray * varray_initfrom(size_t esize, size_t len, void * data) {
    varray * inst = varray_init(esize, len);
    memmove(varray_data(inst), data, varray_len(inst)*varray_esize(inst));
    return inst;
}

inline void varray_free(varray * inst) {
    free(varray_data(inst));
    free(inst);
}

inline void varray_resize(varray * inst, size_t len) {
    varray_data(inst) = realloc(varray_data(inst), len*varray_esize(inst));
    varray_len(inst) = len;
}

inline void varray_clear(varray * inst) {
    memset(varray_data(inst), 0, varray_len(inst)*varray_esize(inst));
}

inline void varray_reset(varray * inst) {
    varray_resize(inst, 0);
}


inline void valist_insert(varray * inst, size_t ind, void * val) {
    varray_resize(inst, varray_len(inst)+1);
    memmove(varray_data(inst)+(ind*varray_esize(inst))+varray_esize(inst), varray_data(inst)+(ind*varray_esize(inst)), varray_len(inst)-ind);
    memmove(varray_data(inst)+ind, val, varray_esize(inst));
}

inline void * valist_remove(varray * inst, size_t ind) {
    void * ret = malloc(varray_esize(inst));
    memmove(ret, varray_data(inst)+ind, varray_esize(inst));
    memmove(varray_data(inst)+(ind*varray_esize(inst))-varray_esize(inst), varray_data(inst)+(ind*varray_esize(inst)), varray_len(inst)-ind);
    varray_resize(inst, varray_len(inst)-1);
    return ret;
}

inline void valist_push(varray * inst, void * val) {
    valist_insert(inst, varray_len(inst), val);
}

inline void * valist_pop(varray * inst) {
    return valist_remove(inst, varray_len(inst)-varray_esize(inst));
}


inline void vaqueue_push(varray * inst, void * val) {
    varray_resize(inst, varray_len(inst)+1);
    memmove(varray_data(inst)+varray_len(inst)-varray_esize(inst), val, varray_esize(inst));
}

inline void * vaqueue_pop(varray * inst) {
    void * ret = malloc(varray_esize(inst));
    memmove(ret, varray_data(inst), varray_esize(inst));
    memmove(varray_data(inst), varray_data(inst)+varray_esize(inst), varray_len(inst)-varray_esize(inst));
    varray_resize(inst, varray_len(inst)-varray_esize(inst));
    return ret;
}

inline void * vaqueue_peek(varray * inst) {
    void * ret = malloc(varray_esize(inst));
    memmove(ret, varray_data(inst), varray_esize(inst));
    return ret;
}


inline void vastack_push(varray * inst, void * val) {
    varray_resize(inst, varray_len(inst)+1);
    memmove(varray_data(inst)+varray_len(inst)-varray_esize(inst), val, varray_esize(inst));
}

inline void * vastack_pop(varray * inst) {
    void * ret = malloc(varray_esize(inst));
    memmove(ret, varray_data(inst)+varray_len(inst)-varray_esize(inst), varray_esize(inst));
    varray_resize(inst, varray_len(inst)-1);
    return ret;
}

inline void * vastack_peek(varray * inst) {
    void * ret = malloc(varray_esize(inst));
    memmove(ret, varray_data(inst)+varray_len(inst)-varray_esize(inst), varray_esize(inst));
    return ret;
}