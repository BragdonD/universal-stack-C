#include <stdlib.h>
#include "linkedlist.h"
#include "stack.h"

/// @brief Function to create a stack
/// @return Return an empty stack
stack* stack_create() {
    stack* temp = NULL;
    temp = malloc(sizeof *temp);
    if(temp == NULL) return NULL;
    temp->head = NULL;
    temp->size = 0;
    return temp;
}

/// @brief Function to push a new element on the stack
/// @param q a stack
/// @param elem the new element
/// @return true on success
bool stack_push(stack* q, void* elem) {
    linkedList* new_elem = linkedlist_createNode(elem);
    if(new_elem == NULL) return false;
    q->head = linkedList_insert_first(q->head, new_elem);
    q->size += 1;
    return true;
}


/// @brief Function to pop an element from the top of the stack
/// @param q a stack
/// @return the data of the removed element
void* stack_pop(stack* q) {
    linkedList* temp = linkedList_delete_head(q->head);
    void* data = NULL;
    if(temp == NULL) return NULL;
    data = temp->data;
    q->head = temp;
    q->size = q->size - 1;
    return data;
}


/// @brief Function to test if a stack is empty
/// @param q a stack
/// @return true or false
bool stack_empty(stack* q) {
    return (q->size == 0);
}

/// @brief Function to get the data at the front of the stack
/// @param q a stack
/// @return pointer of toward the data at the front of the stack
void* stack_front(stack *q) {
    return linkedList_first(q->head)->data;
}

/// @brief Function to get the stack size
/// @param q a stack
/// @return the size of the stack
size_t stack_size(stack* q) {
    return q->size;
}

/// @brief Function to free a stack
/// @param q a stack
/// @param free_data function pointer to handle the data inside the stack 
void stack_free(stack* q, void (*free_data)(void*)) {
    linkedList_free(q->head, free_data);
    free(q);
}

/// @brief Function to create a list from an array of value
/// @param arr The array
/// @param len The length of the array
/// @param type_size the size type of the array
/// @return the head pointer of the list
stack* stack_create_from_list(void* arr, int len, size_t type_size) {
    stack* temp = stack_create();
    if(temp == NULL) return NULL;
    for(int i=0; i<len; i++) {
        stack_push(temp,(((char*)arr) + (i) * type_size));
    }
    return temp;
}