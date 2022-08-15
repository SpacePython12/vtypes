#include "vstring.h"
#include <ctype.h>
#include <math.h>
#include <string.h>

vstring *vstring_new() {
    vstring *vs = malloc(sizeof(vstring));
    if (vs == NULL) {
        return NULL;
    }
    vs->data = malloc(0);
    vs->length = 0;
    return vs;
}

vstring *vstring_from(char *data, size_t len) {
    vstring *vs = vstring_new();
    if (vs == NULL) {
        return NULL;
    }
    vs->data = malloc(len);
    if (vs->data == NULL) {
        vstring_free(vs);
        return NULL;
    }
    memcpy(vs->data, data, len);
    vs->length = len;
    return vs;
}

void vstring_set(vstring *vstr, char *data, size_t len) {
    vstr->data = malloc(len);
    if (vstr->data == NULL) {
        return;
    }
    memcpy(vstr->data, data, len);
    vstr->length = len;
}

void vstring_free(vstring *vs) {
    free(vs->data);
    free(vs);
}

size_t vstring_length(vstring *vs) {
    return vs->length;
}

char *vstring_data(vstring *vs) {
    char * data = malloc(vs->length);
    if (data == NULL) {
        return NULL;
    }
    memcpy(data, vs->data, vs->length);
}

char *vstring_ndata(vstring *vs, size_t offset, size_t size) {
    char * data = malloc(size);
    if (data == NULL) {
        return NULL;
    }
    memcpy(data, vs->data + offset, size);
}

void vstring_append(vstring *vsa, vstring *vsb) {
    char *data = malloc(vsa->length + vsb->length);
    if (data == NULL) {
        return;
    }
    memcpy(data, vsa->data, vsa->length);
    memcpy(data + vsa->length, vsb->data, vsb->length);
    free(vsa->data);
    vsa->data = data;
    vsa->length += vsb->length;
}

void vstring_append_string(vstring *vsa, char *str, size_t len) {
    char *data = malloc(vsa->length + len);
    if (data == NULL) {
        return;
    }
    memcpy(data, vsa->data, vsa->length);
    memcpy(data + vsa->length, str, len);
    free(vsa->data);
    vsa->data = data;
    vsa->length += len;
}

void vstring_append_char(vstring *vsa, char c) {
    char *data = malloc(vsa->length + 1);
    if (data == NULL) {
        return;
    }
    memcpy(data, vsa->data, vsa->length);
    data[vsa->length] = c;
    free(vsa->data);
    vsa->data = data;
    vsa->length += 1;
}

int vstring_compare(vstring *vsa, vstring *vsb) {
    return memcmp(vsa->data, vsb->data, min(vsa->length, vsb->length));
}

int vstring_compare_string(vstring *vsa, char *str, size_t len) {
    return memcmp(vsa->data, str, min(vsa->length, len));
}

int vstring_icompare(vstring *vsa, vstring *vsb) {
    return strncasecmp(vsa->data, vsb->data, min(vsa->length, vsb->length));
}

int vstring_icompare_string(vstring *vsa, char *str, size_t len) {
    return strncasecmp(vsa->data, str, min(vsa->length, len));
}

size_t vstring_count(vstring *vsa, vstring *vsb) {
    size_t ret = 0;
    for (size_t i = 0; i < vsa->length; i++) {
        if (vsa->data[i] == vsb->data[0]) {
            if (memcmp(vsa->data + i, vsb->data, vsb->length) == 0) {
                ret++;
            }
        }
    }
    return ret;
}

size_t vstring_count_string(vstring *vsa, char *str, size_t len) {
    size_t ret = 0;
    for (size_t i = 0; i < vsa->length; i++) {
        if (vsa->data[i] == str[0]) {
            if (memcmp(vsa->data + i, str, len) == 0) {
                ret++;
            }
        }
    }
    return ret;
}

size_t vstring_count_char(vstring *vsa, char c) {
    size_t ret = 0;
    for (size_t i = 0; i < vsa->length; i++) {
        if (vsa->data[i] == c) {
            ret++;
        }
    }
    return ret;
}

size_t vstring_icount(vstring *vsa, vstring *vsb) {
    size_t ret = 0;
    for (size_t i = 0; i < vsa->length; i++) {
        if (tolower(vsa->data[i]) == tolower(vsb->data[0])) {
            if (strncasecmp(vsa->data + i, vsb->data, vsb->length) == 0) {
                ret++;
            }
        }
    }
    return ret;
}

size_t vstring_icount_string(vstring *vsa, char *str, size_t len) {
    size_t ret = 0;
    for (size_t i = 0; i < vsa->length; i++) {
        if (tolower(vsa->data[i]) == tolower(str[0])) {
            if (strncasecmp(vsa->data + i, str, len) == 0) {
                ret++;
            }
        }
    }
    return ret;
}

size_t vstring_icount_char(vstring *vsa, char c) {
    size_t ret = 0;
    for (size_t i = 0; i < vsa->length; i++) {
        if (tolower(vsa->data[i]) == tolower(c)) {
            ret++;
        }
    }
    return ret;
}

size_t vstring_find(vstring *vsa, vstring * vsb, size_t ** positions) {
    size_t ret = 0;
    for (size_t i = 0; i < vsa->length; i++) {
        if (vsa->data[i] == vsb->data[0]) {
            if (memcmp(vsa->data + i, vsb->data, vsb->length) == 0) {
                if (positions != NULL) {
                    positions[ret] = malloc(sizeof(size_t));
                    if (positions[ret] == NULL) {
                        return 0;
                    }
                    *positions[ret] = i;
                }
                ret++;
            }
        }
    }
    return ret;
}