#include <stdlib.h>
#include "linkedlist.h"

linkedList* linkedlist_createNode(void* data) {
    linkedList* temp = NULL;
    temp = malloc(sizeof(*temp));
    if(temp == NULL) return NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void* linkedList_first_data(linkedList* head) {
    return head->data;
}

void* linkedList_last_data(linkedList* head) {
    linkedList* pnow = head;
    if(pnow == NULL) return NULL;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    return pnow->data;
}

linkedList* linkedList_first(linkedList* head) {
    return head;
}

linkedList* linkedList_last(linkedList* head) {
    linkedList* pnow = NULL;
    if(head == NULL) return NULL;
    pnow = head;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    return pnow;
}

linkedList* linkedList_insert_last(linkedList* head, linkedList* elem) {
    linkedList *pnow = head;
    if(pnow == NULL) return elem;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    pnow->next = elem;
    return head;
}

linkedList* linkedList_insert_first(linkedList* head, linkedList* elem) {
    if(head == NULL) return elem;
    if(elem == NULL) return head;
    return linkedList_insert_last(elem, head);
}

linkedList* linkedList_insert_after(linkedList* head, linkedList* elem) {
    if(head == NULL) return elem;
    if(elem == NULL) return head;
    head->next = linkedList_insert_last(elem, head->next);
    return head;
}

void* linkedList_delete_last(linkedList* head) {
    linkedList *pnow = head;
    linkedList *ppred = head;
    void *data = NULL;
    if(pnow == NULL) return data;
    while(pnow->next != NULL) {
        ppred = pnow;
        pnow = pnow->next;
    }
    ppred->next = NULL;
    data = pnow->data;
    free(pnow);
    return data;
}

void* linkedList_delete_after(linkedList* head) {
    linkedList *pnow = NULL; 
    void* data = NULL;
    if(head->next == NULL) return NULL;
    pnow = head->next;
    data = pnow->data;
    head->next = head->next->next;
    free(pnow);
    return data;
}

linkedList* linkedList_delete_head(linkedList* head) {
    linkedList *toreturn = NULL;
    if(head == NULL) return NULL;
    toreturn = malloc(sizeof *toreturn);
    if(toreturn == NULL) return NULL;
    toreturn->next = head->next;
    toreturn->data = head->data;
    free(head);
    return toreturn;
}

void linkedList_free(linkedList* head) {
    if(head == NULL) return;
    linkedList_free(head->next);
    free(head);
}

linkedList* linkedList_create_from_list(void* arr, int len, size_t type_size) {
    linkedList* head = linkedlist_createNode(arr);
    if(head == NULL) return NULL;
    for(int i=1; i<len; i++) {
        head = linkedList_insert_last(head,linkedlist_createNode((((char*)arr) + (i) * type_size)));
    }
    return head;
}