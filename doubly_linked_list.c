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

//insertion at a given node

struct Node* insertion_given_node(struct Node* head, int pos, int data)
{
    struct Node* new_data = createNode(data);
    if (pos == 1){
        new_data -> next = head;
        if (head != NULL){
            head -> prev = new_data;
        }

        head = new_data;
        return head;
    }

    struct Node* curr = head;

    for (int i = 1; i < pos -1 && curr != NULL;i++){
        curr = curr-> next;
    }

    if (curr == NULL){
        printf("position is out of bounds");
        free(new_data);
        return head;
    }

    new_data -> prev = curr;
    new_data -> next = curr -> next;
    curr -> next = new_data;
    if (new_data -> next != NULL){
        new_data -> next -> prev = new_data;
    }

    return head;

};



int main(){
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(4);
    struct Node* fifth = createNode(5);
    struct Node* sixth = createNode(6);
    struct Node* seventh = createNode(7);

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
    int pos;
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    printf("Enter the position in which the data to be inserted: ");
    scanf("%d", &pos);
    head = insertion_given_node(head, pos, data);
    printf("after insertion: ");
    printing(head); 
    return 0;

}