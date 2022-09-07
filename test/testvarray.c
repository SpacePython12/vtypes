#include <stdio.h>
#include "varray.h"
#include "valist.h"
#include "vaqueue.h"
#include "vastack.h"
#include "vutil.h"

void testlist() {
    char src[5] = {1,2,3,4,5};
    varray * list = varray_initfrom(sizeof(char), 5, &src);
    valist_push(list, vague_from(char, 6));
    printf("List pop: %d\n", vague_to(char, valist_pop(list)));
    valist_insert(list, 3, vague_from(char, 7));
    printf("List remove: %d\n", vague_to(char, valist_remove(list, 3)));
}

void testqueue() {
    char src[5] = {1,2,3,4,5};
    varray * queue = varray_initfrom(sizeof(char), 5, &src);
    vaqueue_push(queue, vague_from(char, 6));
    printf("Queue peek: %d\n", vague_to(char, vaqueue_peek(queue)));
    printf("Queue pop: %d\n", vague_to(char, vaqueue_pop(queue)));
}

void teststack() {
    char src[5] = {1,2,3,4,5};
    varray * stack = varray_initfrom(sizeof(char), 5, &src);
    vastack_push(stack, vague_from(char, 6));
    printf("Stack peek: %d\n", vague_to(char, vastack_peek(stack)));
    printf("Stack pop: %d\n", vague_to(char, vastack_pop(stack)));
}

int main() {
    testlist();
    testqueue();
    teststack();
    return 0;
}