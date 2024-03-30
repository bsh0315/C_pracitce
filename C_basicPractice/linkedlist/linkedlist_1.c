#include <stdio.h>
#include <stdlib.h>

// 노드 데이터
typedef struct node {
    int data;
    struct node* next;
}list;


int main(){
    list* head;
    head = (list*)malloc(sizeof(list));

    list* node1;
    node1 = (list*)malloc(sizeof(list));
    head -> next = node1;
    node1 -> data = 10;

    list* node2;
    node2 = (list*)malloc(sizeof(list));
    node1->next = node2;
    node2->data = 20;

    node2->next = NULL;

    list* curr = head->next;
    while (curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }

    free(head);
    free(node1);
    free(node2);

    return 0;
}