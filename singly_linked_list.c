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
    return newNode;
}


//printing the linked list
void printing (struct Node* head){
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


//forward traversal
void ForwardTraversal(struct Node* head){
    struct Node *curr = head;
    while (curr != NULL){
        printf("%d", curr -> data);
        curr = curr->next;
    }
    printf("\n");
}


//insetion in the end
struct Node* insertion_end(struct Node* head, int data)
{
    struct Node* new_node = createNode(data);
    if (head == NULL){
        return new_node;
    }
    struct Node* last = head;
    while (last -> next != head){
        last = last-> next;
    }
    last -> next = new_node;
    return head;   
}



//insetion in the beginning
struct Node* insertion_begin(struct Node* head, int data)
{
    struct Node* new_node = createNode(data);
    new_node -> next = head;
    return new_node;
};


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

    // printf("after traversal: ");
    // ForwardTraversal(head);

    printf("before insertion: ");
    printing(head);
    int data = 89;
    printf("after insertion: ");
    head = insertion_end(head, data);
    printing(head);
}