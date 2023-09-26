#include <stdio.h>

typedef struct
{
    int value;
    struct No *right, *left;
} No;

void insertNode(No** root, int value){
    if(*root == NULL){
        *root =  malloc(sizeof(No));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;

    }else{
        if(value < (*root)->value){
            insertNode(&((*root)->left), value);
        }else{
            insertNode(&((*root)->right), value);
        }
    }
}

void print(No *root){
    if(root){
        print(root->left);
        printf("%d", root->value);
        print(root->right);
    }
}

int main(){

    No *root = NULL;

    insertNode(&root, 15);
    insertNode(&root, 18);
    insertNode(&root, 25);

    print(&root);

    return 0;
}
