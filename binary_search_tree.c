#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int info;
    struct tree *lchild;
    struct tree *rchild;
} bst;

void insert(bst **root, int data) {
    bst *newnode = (bst *)malloc(sizeof(bst));
    newnode->info = data;
    newnode->lchild = newnode->rchild = NULL;

    if (*root == NULL) {
        *root = newnode;
        return;
    }

    bst *temp = *root;
    while (1) {
        if (data < temp->info) {
            if (temp->lchild == NULL) {
                temp->lchild = newnode;
                return;
            }
            temp = temp->lchild;
        } else if (data > temp->info) {
            if (temp->rchild == NULL) {
                temp->rchild = newnode;
                return;
            }
            temp = temp->rchild;
        } else {
            free(newnode);
            return;
        }
    }
}

void inorder(bst *root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d \t", root->info);
        inorder(root->rchild);
    }
}

void preorder(bst *root) {
    if (root != NULL) {
        printf("%d \t", root->info);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(bst *root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d \t", root->info);
    }
}

int main() {
    int data;
    int choice;
    bst *root = NULL;

    do {
        printf("Enter 1 to insert, Enter 2 for inorder, Enter 3 for preorder, Enter 4 for postorder, Enter 0 to exit: ");
        scanf("%d", &choice);  
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);  
                insert(&root, data);  
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid Option Selected\n");
                break;
        }
    } while (1);

    return 0;  
}
