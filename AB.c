#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int value;
    struct No *right, *left;
} No;

void insertNode(No **root, int value)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(No));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        if (value < (*root)->value)
        {
            insertNode(&((*root)->left), value);
        }
        else
        {
            insertNode(&((*root)->right), value);
        }
    }
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

    No *root = NULL;
    int *f;

    for (int i = 0; i < 50; i++)
    {
        int randomValue = rand() % 1000; // Gera um valor aleatório entre 0 e 99
        insertNode(&root, randomValue);
    }

    search(5, root, f);

    print("%d", f);

    // print(root);

    return 0;
}
