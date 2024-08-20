#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int newData)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;
};

void ForwardTraversal(struct Node* head){
    struct Node *curr = head;
    while (curr != NULL){
        printf("%d", curr -> data);
        curr = curr->next;
    }
    printf("\n");
}


int main(){
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(4);
    struct Node* fifth = createNode(5);
    struct Node* sixth = createNode(6);
    struct Node* seventh = createNode(7);
    struct Node* eigth= createNode(8);
    struct Node* ninth = createNode(9);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;
    seventh -> next = eigth;
    eigth -> next = ninth;

    printf("after traversal: ");
    ForwardTraversal(head);
}