#include "vmap.h"
#include <stdio.h>
#include <string.h>

char * strmap_print(vague_t key, vague_t val) {
    size_t size = 7+(key ? strlen(key) : 0)+(val ? strlen(val) : 0);
    char * ret = malloc(size);
    strcpy(ret, "\"");
    strcat(ret, (key ? key : ""));
    strcat(ret, "\": \"");
    strcat(ret, (val ? val : ""));
    strcat(ret, "\"");
    return ret;
}

void testvmap() {
    printf("Initializing a string-string map.\n");
    vmap * strmap = vmap_init(IS_NULLTERM, IS_NULLTERM);
    printf("Adding value 'bar' with key 'foo', and value 'baz' with key 'boo'.\n");
    vmap_add(strmap, "foo", "bar");
    vmap_add(strmap, "boo", "baz");
    printf("Retreived value from 'foo': %s\n", vmap_get(strmap, "foo"));
    printf("Map contents: %s\n", vmap_print(strmap, &strmap_print));
    printf("Setting value 'foobar' at 'foo'.\n");
    vmap_set(strmap, "foo", "foobar");
    printf("Map contents: %s\n", vmap_print(strmap, &strmap_print));
    printf("Removing 'foo'.\n");
    vmap_rem(strmap, "foo");
    printf("Map contents: %s\n", vmap_print(strmap, &strmap_print));
    printf("Freeing string-string map.\n");
    vmap_free(strmap);
    printf("Finished testing vmap.\n");
}

int main() {
    testvmap();
    return 0;
}