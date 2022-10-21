#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct linkedList linkedList;

typedef struct stack {
    linkedList* head;
    size_t size;
} stack;

stack* stack_create();
stack* stack_create_from_list(void* arr, int len, size_t type_size);
bool stack_push(stack* q, void* elem);
void* stack_pop(stack* q);
bool stack_empty(stack* q);
void* stack_front(stack *q);
size_t stack_size(stack* q);
void stack_free(stack* q);

#endif