#include "vstring.h"
#include <ctype.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

// https://stackoverflow.com/a/779960
// You must free the result if result is non-NULL.
size_t str_replace(char **target, size_t targetlen, const char *rep, size_t replen, const char *with, size_t withlen) {
    char *orig = *target;
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    size_t len_rep;  // length of rep (the string to remove)
    size_t len_with; // length of with (the string to replace rep with)
    size_t len_front; // distance between rep and end of last rep
    size_t count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return;
    len_rep = replen;
    if (len_rep == 0)
        return; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = withlen;

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(targetlen + (len_with - len_rep) * count + 1);

    if (!result)
        return;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    if (result != NULL) {
        free(*target);
        *target = result;
    }
    return count;
}

vstring_t *vstring_new() {
    vstring_t *vs = malloc(sizeof(vstring_t));
    if (vs == NULL) {
        return NULL;
    }
    vs->data = malloc(0);
    vs->length = 0;
    return vs;
}

vstring_t *vstring_from(char *data, size_t len) {
    vstring_t *vs = vstring_new();
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

void vstring_set(vstring_t *vstr, char *data, size_t len) {
    vstr->data = malloc(len);
    if (vstr->data == NULL) {
        return;
    }
    memcpy(vstr->data, data, len);
    vstr->length = len;
}

void vstring_free(vstring_t *vs) {
    free(vs->data);
    free(vs);
}

size_t vstring_length(vstring_t *vs) {
    return vs->length;
}

char *vstring_data(vstring_t *vs) {
    char * data = malloc(vs->length);
    if (data == NULL) {
        return NULL;
    }
    memcpy(data, vs->data, vs->length);
}

char *vstring_ndata(vstring_t *vs, size_t offset, size_t size) {
    char * data = malloc(size);
    if (data == NULL) {
        return NULL;
    }
    memcpy(data, vs->data + offset, size);
}

void vstring_append(vstring_t *vsa, vstring_t *vsb) {
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

void vstring_append_string(vstring_t *vsa, char *str, size_t len) {
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

void vstring_append_char(vstring_t *vsa, char c) {
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

int vstring_compare(vstring_t *vsa, vstring_t *vsb) {
    return strncmp(vsa->data, vsb->data, min(vsa->length, vsb->length));
}

int vstring_compare_string(vstring_t *vsa, char *str, size_t len) {
    return strncmp(vsa->data, str, min(vsa->length, len));
}

int vstring_icompare(vstring_t *vsa, vstring_t *vsb) {
    return strncasecmp(vsa->data, vsb->data, min(vsa->length, vsb->length));
}

int vstring_icompare_string(vstring_t *vsa, char *str, size_t len) {
    return strncasecmp(vsa->data, str, min(vsa->length, len));
}
// basic counting function
size_t basic_count(vstring_t * vsa, char check, char * str, size_t len, int (*compare)(char *, char *, size_t)) {
    size_t count = 0;
    for (size_t i = 0; i < vsa->length; i++) { // Iterate through the string
        if (vsa->data[i] == check) { // Is the current character the check character?
            if (compare(vsa->data + i, str, len) == 0) { // Compare the current character to the string
                count++; // If they match, increment the count
            }
        }
    }
    return count;
}
// basic searching function
size_t basic_find(vstring_t * vsa, char check, char * str, size_t len, size_t ** positions, int (*compare)(char *, char *, size_t)) {
    size_t ret = 0;
    *positions = malloc(0); // Allocate memory for the positions array (not really lol)
    for (size_t i = 0; i < vsa->length; i++) { // Iterate through the string
        if (vsa->data[i] == check) { // Is the current character the check character?
            if (compare(vsa->data + i, str, len) == 0) { // Compare the current character to the string
                *positions = realloc(*positions, (ret + 1) * sizeof(size_t)); // Allocate memory for the position
                (*positions)[ret] = i; // Set the position
                ret++; // Increment the count
            }
        }
    }
    return ret;
}
// For use with char compare
int dummy_compare(char *a, char *b, size_t len) {
    return 0;
}

size_t vstring_count(vstring_t *vsa, vstring_t *vsb) {
    return basic_count(vsa, vsb->data[0], vsb->data, vsb->length, &strncmp);
}

size_t vstring_count_string(vstring_t *vsa, char *str, size_t len) {
    return basic_count(vsa, str[0], str, len, &strncmp);
}

size_t vstring_count_char(vstring_t *vsa, char c) {
    return basic_count(vsa, c, NULL, 0, &dummy_compare);
}

size_t vstring_find(vstring_t *vsa, vstring_t * vsb, size_t ** positions) {
    return basic_find(vsa, vsb->data[0], vsb->data, vsb->length, positions, &strncmp);
}

size_t vstring_find_string(vstring_t *vsa, char *str, size_t len, size_t ** positions) {
    return basic_find(vsa, str[0], str, len, positions, &strncmp);
}

size_t vstring_find_char(vstring_t *vsa, char c, size_t ** positions) {
    return basic_find(vsa, c, NULL, 0, positions, &dummy_compare);
}

vstring_t * vstring_lower(vstring_t *vsa) {
    vstring_t *ret = vstring_from(vsa->data, vsa->length);
    for (size_t i = 0; i < vsa->length; i++) {
        ret->data[i] = tolower(vsa->data[i]);
    }
    return ret;
}

vstring_t * vstring_upper(vstring_t *vsa) {
    vstring_t *ret = vstring_from(vsa->data, vsa->length);
    for (size_t i = 0; i < vsa->length; i++) {
        ret->data[i] = toupper(vsa->data[i]);
    }
    return ret;
}

size_t vstring_replace(vstring_t *vsa, vstring_t *vsb, vstring_t *vsc) {
    str_replace(&vsa->data, vsa->length, vsb->data, vsb->length, vsc->data, vsc->length);
}

size_t vstring_replace_string(vstring_t *vsa, char *str, size_t len, char * str2, size_t len2) {
    str_replace(&vsa->data, vsa->length, str, len, str2, len2);
}

size_t vstring_replace_char(vstring_t *vsa, char c, char c2) {
    str_replace(&vsa->data, vsa->length, &c, 1, &c2, 1);
}

size_t vstring_remove(vstring_t *vsa, vstring_t *vsb) {
    str_replace(&vsa->data, vsa->length, vsb->data, vsb->length, "", 0);
}

size_t vstring_remove_string(vstring_t *vsa, char *str, size_t len) {
    str_replace(&vsa->data, vsa->length, str, len, "", 0);
}

size_t vstring_remove_char(vstring_t *vsa, char c) {
    str_replace(&vsa->data, vsa->length, &c, 1, "", 0);
}