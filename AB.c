#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int value;
    struct No *right, *left;
} No;

No *createNode(int value)
{
    No *newNode = malloc(sizeof(No));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value;

    return newNode;
}

void insertNode(No **root, int value)
{
    No* pt = *root;
    int f = -1;
    search(value, pt, &f);
    printf("%d", f);
}

void search(int value, No *root, int *f)
{
    if (root == NULL)
    {
        *f = 0; // Define *f como 0 para indicar que o elemento não foi encontrado
    }
    else
    {
        if (root->value == value)
        {
            *f = 1; // Define *f como 1 para indicar que o elemento foi encontrado
        }
        else
        {
            if (value < root->value)
            {
                if (root->left == NULL)
                {
                    *f = 2; // Define *f como 2 para indicar que o elemento não existe na subárvore esquerda
                }
                else
                {
                    root = root->left;
                    search(value, root, f);
                }
            }
            else
            {
                if (root->right == NULL)
                {
                    *f = 3; // Define *f como 3 para indicar que o elemento não existe na subárvore direita
                }
                else
                {
                    root = root->right;
                    search(value, root, f);
                }
            }
        }
    }
}

void print(No *root)
{
    if (root)
    {
        print(root->left);
        printf("%d -> ", root->value);
        print(root->right);
    }
}

int main()
{

    No *root = createNode(15);
    int f = 0;

    insertNode(&root, 16);

    // print(root);

    return 0;
}
