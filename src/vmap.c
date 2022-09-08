#include "vmap.h"
#include "valist.h"
#include "vutil.h"

#include <string.h>

inline vmap * vmap_init(size_t ksize, size_t vsize) {
    vmap * ret = malloc(sizeof(vmap));
    varray * tmparr = varray_init(sizeof(vmap_pair_t), 0);
    memmove(&ret->arr, tmparr, sizeof(varray));
    free(tmparr);
    ret->ksize = ksize;
    ret->vsize = vsize;
    return ret;
}

inline vmap_pair_t * vmap_getp_at(vmap * inst, size_t index) {
    if (index >= (&inst->arr)->nmemb) {return NULL;}
    return (vmap_pair_t *)varray_at(&inst->arr, index);
}

inline void _vmap_pair_set(vmap_pair_t * pair, vague_t key, size_t ksize, vague_t val, size_t vsize) {
    if (!ksize) {
        ksize = strlen((char *)key);
    }
    if (!vsize) {
        vsize = strlen((char *)val);
    }
    pair->keyhash = vutil_hash(key, ksize);
    pair->key = malloc(ksize+1);
    pair->val = malloc(vsize+1);
    memmove(pair->key, key, ksize+1);
    memmove(pair->val, val, vsize+1);
}

inline void _vmap_pair_free(vmap_pair_t * pair) {
    free(pair->key);
    free(pair->val);
}

inline void vmap_reset(vmap * inst) {
    for (size_t i = 0; i < vmap_len(inst); i++) {
        _vmap_pair_free(vmap_getp_at(inst, i));
    }
    varray_resize(&inst->arr, 0);
}

inline void vmap_free(vmap * inst) {
    if (varray_data(&inst->arr)) {vmap_reset(inst);}
    free(inst);
}

inline size_t vmap_find(vmap * inst, vague_t key) {
    unsigned long keyhash;
    if (inst->ksize) {
        keyhash = vutil_hash(key, inst->ksize);
    } else {
        keyhash = vutil_hash(key, strlen((char *) key));
    }
    vmap_pair_t * pair;
    for (size_t i = 0; i < vmap_len(inst); i++) {
        pair = vmap_getp_at(inst, i);
        if (pair->keyhash == keyhash) return i;
    }
    return __SIZE_MAX__;
}

inline vmap_pair_t * vmap_getp(vmap * inst, vague_t key) {
    size_t index = vmap_find(inst, key);
    if (index == __SIZE_MAX__) {
        return NULL;
    } else {
        return vmap_getp_at(inst, index);
    }
}

inline vague_t vmap_get(vmap * inst, vague_t key) {
    vmap_pair_t * pair = vmap_getp(inst, key);
    if (!pair) {return NULL;}
    return pair->val;
}

inline void vmap_set(vmap * inst, vague_t key, vague_t val) {
    vmap_pair_t * pair = vmap_getp(inst, key);
    if (!pair) {return;}
    if (!inst->vsize) {
        pair->val = realloc(pair->val, strlen(val)+1);
        memmove(pair->val, val, strlen(val)+1);
    } else {
        memmove(pair->val, val, inst->vsize);
    }
}

inline void vmap_add(vmap * inst, vague_t key, vague_t val) {
    vmap_pair_t pair;
    _vmap_pair_set(&pair, key, inst->ksize, val, inst->vsize);
    valist_push(&inst->arr, &pair);
}

inline void vmap_rem(vmap * inst, vague_t key) {
    size_t index = vmap_find(inst, key);
    if (index == __SIZE_MAX__) {return;}
    _vmap_pair_free(vmap_getp_at(inst, index));
    valist_remove(&inst->arr, index);
}

char * vmap_print(vmap * inst, vmap_printpair_fn pfn) {
    size_t size = 1;
    char * ret = malloc(size);
    char * pairstr;
    vmap_pair_t * pair;
    size++;
    ret = realloc(ret, size);
    strcpy(ret, "{");
    for (size_t i = 0; i < vmap_len(inst); i++) {
        pair = vmap_getp_at(inst, i);
        if (!pair) {continue;}
        pairstr = pfn(pair->key, pair->val);
        size += strlen(pairstr);
        ret = realloc(ret, size);
        strcat(ret, pairstr);
        if (i < vmap_len(inst)-1) {
            size += 2;
            ret = realloc(ret, size);
            strcat(ret, ", ");
        }
    }
    size++;
    ret = realloc(ret, size);
    strcat(ret, "}");
    return ret;
}