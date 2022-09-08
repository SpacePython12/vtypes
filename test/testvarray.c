#include <stdio.h>
#include "varray.h"
#include "valist.h"
#include "vaqueue.h"
#include "vastack.h"
#include "vutil.h"

void testlist() {
    short src[5] = {0xf0f1,0xf2f3,0xf4f5,0xf6f7,0xf8f9};
    varray * list = varray_initfrom(sizeof(short), 5, &src);
    valist_push(list, vague_from(short, 0xfafb));
    printf("List pop: %x\n", vague_to(short, valist_pop(list)));
    valist_insert(list, 3, vague_from(short, 0xfcfd));
    valist_remove(list, 3);
    varray_free(list);
}

void testqueue() {
    short src[5] = {0xf0f1,0xf2f3,0xf4f5,0xf6f7,0xf8f9};
    varray * queue = varray_initfrom(sizeof(short), 5, &src);
    vaqueue_push(queue, vague_from(short, 0xfafb));
    printf("Queue peek: %x\n", vague_to(short, vaqueue_peek(queue)));
    printf("Queue pop: %x\n", vague_to(short, vaqueue_pop(queue)));
    varray_free(queue);
}

void teststack() {
    short src[5] = {0xf0f1,0xf2f3,0xf4f5,0xf6f7,0xf8f9};
    varray * stack = varray_initfrom(sizeof(short), 5, &src);
    vastack_push(stack, vague_from(short, 0xfafb));
    printf("Stack peek: %x\n", vague_to(short, vastack_peek(stack)));
    printf("Stack pop: %x\n", vague_to(short, vastack_pop(stack)));
    varray_free(stack);
}

int main() {
    testlist();
    testqueue();
    teststack();
    return 0;
}