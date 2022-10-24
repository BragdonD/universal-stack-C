#include <stdlib.h>
#include "linkedlist.h"
#include "stack.h"

stack* stack_create() {
    stack* temp = NULL;
    temp = malloc(sizeof *temp);
    if(temp == NULL) return NULL;
    temp->head = NULL;
    temp->size = 0;
    return temp;
}

bool stack_push(stack* q, void* elem) {
    linkedList* new_elem = linkedlist_createNode(elem);
    if(new_elem == NULL) return false;
    q->head = linkedList_insert_first(q->head, new_elem);
    q->size += 1;
    return true;
}

void* stack_pop(stack* q) {
    linkedList* temp = linkedList_delete_head(q->head);
    void* data = NULL;
    if(temp == NULL) return NULL;
    data = temp->data;
    q->head = temp->next;
    q->size = q->size - 1;
    free(temp);
    return data;
}

bool stack_empty(stack* q) {
    return (q->size == 0);
}

void* stack_front(stack *q) {
    return linkedList_first(q->head)->data;
}

size_t stack_size(stack* q) {
    return q->size;
}

void stack_free(stack* q, void (*free_data)(void*)) {
    linkedList_free(q->head, free_data);
    free(q);
}

stack* stack_create_from_list(void* arr, int len, size_t type_size) {
    stack* temp = stack_create();
    if(temp == NULL) return NULL;
    for(int i=0; i<len; i++) {
        stack_push(temp,(((char*)arr) + (i) * type_size));
    }
    return temp;
}