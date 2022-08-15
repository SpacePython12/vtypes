#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#include "vbuffer.h"
// test all the functions in vbuffer.h

void testproperties()
{
    vbuffer_t *vb = vbuffer_new(16);
    assert(vb != NULL);
    assert(vbuffer_capacity(vb) == 16);
    assert(vbuffer_data(vb) != NULL);
    vbuffer_free(vb);
}

void testmethods()
{
    vbuffer_t *vb = vbuffer_new(20);
    vbuffer_put_array(vb, 0, "foobarboobazgoogizz", 20);
    vbuffer_resize(vb, 10);
    assert(strcmp(vbuffer_data(vb), "foobarboobazgoogizz"));
    vbuffer_clear(vb);
    assert(vbuffer_capacity(vb) == 10);
    assert(vbuffer_data(vb) != NULL);
    assert(((char *)vbuffer_data(vb))[0] == 0);
    vbuffer_free(vb);
}

void testfio()
{
    vbuffer_t *vb = vbuffer_new(0);
    FILE *f = fopen("README.md", "rt");
    assert(f != NULL);
    printf("Reading from file...\n");
    vbuffer_fread(vb, f);
    char *data = malloc(vbuffer_capacity(vb)+1);
    assert(data != NULL);
    memcpy(data, vbuffer_data(vb), vbuffer_capacity(vb));
    data[vbuffer_capacity(vb)] = 0;
    printf("The file is %lu bytes long, and contains: %s\n", vbuffer_capacity(vb), data);
    assert(vbuffer_capacity(vb) > 0);
    fclose(f);
    vbuffer_free(vb);
}

int main() {
    testproperties();
    testmethods();
    testfio();
    return 0;
}