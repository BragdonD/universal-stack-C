#include <stdlib.h>
#include "linkedlist.h"

/// @brief Function to create a node of a linked list
/// @param data a pointer toward the node data.
/// @return a pointer toward the allocated node.
linkedList* linkedlist_createNode(void* data) {
    linkedList* temp = NULL;
    temp = malloc(sizeof(*temp));
    if(temp == NULL) return NULL; ///Error to handle in the caller function
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/// @brief Function to retrieve the data of the first node
/// @param head the head pointer of the linked list.
/// @return a pointer toward the data of the first node.
void* linkedList_first_data(linkedList* head) {
    return head->data;
}

/// @brief Function to retrieve the data
/// @param head the head pointer of the linked list
/// @return return pointer toward the last data of the list
void* linkedList_last_data(linkedList* head) {
    linkedList* pnow = head;
    if(pnow == NULL) return NULL;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    return pnow->data;
}

/// @brief Function to get the pointer of the first node of the linked list
/// @param head The head pointer of the linked list
/// @return the head pointer
linkedList* linkedList_first(linkedList* head) {
    return head;
}

/// @brief Function to get the pointer of the last node of the linked list
/// @param head The head pointer of the linked list
/// @return the rear pointer of the list
linkedList* linkedList_last(linkedList* head) {
    linkedList* pnow = NULL;
    if(head == NULL) return NULL;
    pnow = head;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    return pnow;
}

/// @brief Function to insert a new node at the end of the list
/// @param head Head pointer of the list
/// @param elem Pointer of the new element
/// @return The new head of the list
linkedList* linkedList_insert_last(linkedList* head, linkedList* elem) {
    linkedList *pnow = head;
    if(pnow == NULL) return elem;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    pnow->next = elem;
    return head;
}

/// @brief Function to insert a new node at the beginning of the list
/// @param head Head pointer of the list
/// @param elem Pointer of the new element
/// @return The new head of the list
linkedList* linkedList_insert_first(linkedList* head, linkedList* elem) {
    if(head == NULL) return elem;
    if(elem == NULL) return head;
    return linkedList_insert_last(elem, head);
}

/// @brief Function to insert a new node after the head
/// @param head The head pointer
/// @param elem The new node
/// @return The new head
linkedList* linkedList_insert_after(linkedList* head, linkedList* elem) {
    if(head == NULL) return elem;
    if(elem == NULL) return head;
    head->next = linkedList_insert_last(elem, head->next);
    return head;
}

/// @brief Function to delete the last value of the list
/// @param head The head pointer
/// @return a pointer toward the data
void* linkedList_delete_last(linkedList* head) {
    linkedList *pnow = head;
    linkedList *ppred = head;
    void *data = NULL;
    if(pnow == NULL) return data;
    while(pnow->next != NULL) { ///Find the last element
        ppred = pnow;
        pnow = pnow->next;
    }
    ppred->next = NULL;
    data = pnow->data;
    free(pnow);
    return data;
}

/// @brief Function to delete the element after a given node
/// @param head the node to delete after
/// @return pointer towatd the data stored in the deleted element
void* linkedList_delete_after(linkedList* head) {
    linkedList *pnow = NULL; 
    void* data = NULL;
    if(head == NULL) return NULL;
    if(head->next == NULL) return NULL;
    pnow = head->next;
    data = pnow->data;
    head->next = head->next->next;
    free(pnow);
    return data;
}

/// @brief Function to delete the head pointer of a list
/// @param head the head pointer of the list
/// @return the new head pointer of the list
linkedList* linkedList_delete_head(linkedList* head) {
    linkedList *toreturn = NULL;
    if(head == NULL) return NULL;
    toreturn->next = head->next;
    free(head);
    return toreturn;
}

/// @brief Function to free a list recursively
/// @param head the head pointer
void linkedList_free(linkedList* head, void (*free_data)(void*)) {
    if(head == NULL) return;
    linkedList_free(head->next, free_data);
    if(free_data != NULL)
        free_data(head->data);
    free(head);
}
/// @brief Function to create a list from an array of value
/// @param arr The array
/// @param len The length of the array
/// @param type_size the size type of the array
/// @return the head pointer of the list
linkedList* linkedList_create_from_list(void* arr, int len, size_t type_size) {
    linkedList* head = linkedlist_createNode(arr);
    if(head == NULL) return NULL;
    for(int i=1; i<len; i++) {
        head = linkedList_insert_last(head,linkedlist_createNode((((char*)arr) + (i) * type_size)));
    }
    return head;
}

/// @brief Function to iter the linked list and do action on data of each node.
/// @param head The head pointer
/// @param do_ Pointer function to do an action. Can be NULL if nothing is to be performed.
void linkedList_iter_data(linkedList* head, void (*do_)(void*)) {
    if(head == NULL) return;
    if(do_ == NULL) return;
    do_(head->data);
    linkedList_iter_data(head->next, do_);
}