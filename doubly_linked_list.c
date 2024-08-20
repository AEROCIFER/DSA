#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;    
};

struct Node *createNode(int new_data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = new_data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printing (struct Node* head){
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void forwardTraversal (struct Node* head){
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void reverseTraversal (struct Node* tail){
    struct Node* curr = tail;
    while(curr != NULL){
        printf("%d", curr-> data);
        curr = curr->prev;
    }
    printf("\n");   
}

//insertion of a new node at the beginning
struct Node* insertion_beginning(struct Node* head, int data){
    struct Node* new_node = createNode(data);
    new_node -> next = head;
    if (head != NULL){
        head -> prev = new_node;
    }
    return new_node;
}

//insertion of a new node at the end
struct Node* insertion_end(struct Node* head, int data)
{
    struct Node* new_data = createNode(data);
    if (head == NULL){
        head = new_data;
    }
    else {
        struct Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new_data;
        new_data->prev = curr;
    }
    return head;
};


int main(){
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(4);

    head->next = second;
    second->prev= head;
    second->next = third;
    third->prev= second;
    third->next = fourth;
    fourth->prev = third;

    // printf("Forward Traversal\n");
    // forwardTraversal(head);

    // printf("Backward Traversal\n");
    // reverseTraversal(fourth);
    printf("before insertion: ");
    printing(head);

    head = insertion_end(head, 7);
    printf("after insertion: ");
    printing(head); 
    return 0;
}