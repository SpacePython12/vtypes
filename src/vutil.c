#include "vutil.h"

unsigned long vutil_hash(void * data, size_t len)
{
    unsigned long ret = 19L;
    for (unsigned long i = 0; i < len; i++) {
        ret = (61 * (ret + (unsigned long)*((unsigned char *) data+i)));
    }
    return ret;
}

unsigned char vutil_equals(void * d1, size_t l1, void * d2, size_t l2)
{
    unsigned char ret = 1;
    if (l1 != l2) {
        ret = 0;
    } else {
        for (unsigned long i = 0; i < l1; i++) {
            if (*((unsigned char *) d1+i) != *((unsigned char *) d2+i)) {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}