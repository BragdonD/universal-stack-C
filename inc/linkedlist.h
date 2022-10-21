#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef struct linkedList {
    void* data;
    struct linkedList* next;
} linkedList;

linkedList* linkedlist_createNode(void* data);
void* linkedList_first_data(linkedList* head);
void* linkedList_last_data(linkedList* head);
linkedList* linkedList_first(linkedList* head);
linkedList* linkedList_last(linkedList* head);
linkedList* linkedList_insert_first(linkedList* head, linkedList* elem);
linkedList* linkedList_insert_last(linkedList* head, linkedList* elem);
linkedList* linkedList_insert_after(linkedList* head, linkedList* elem);
void* linkedList_delete_last(linkedList* head);
void* linkedList_delete_after(linkedList* head);
linkedList* linkedList_delete_head(linkedList* head);
void linkedList_free(linkedList* head);
linkedList* linkedList_create_from_list(void* arr, int len, size_t type_size);

#endif