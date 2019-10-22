#include <stdlib.h>
#include <stdio.h>

struct node {
	char data;
	int key;
	struct node * right;
	struct node	* left;
};

void insert(int);
void print_preorder();
void print_inorder();
void print_inorder();

// insert a new node of a binary tree in the first place
void insert(node ** tree, int key)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = key;
        *tree = temp;
        return;
    }

    if(key < (*tree)->data)
    {
        insert(&(*tree)->left, key);
    }
    else if(key > (*tree)->data)
    {
        insert(&(*tree)->right, key);
    }

}

// preorder traversal of a binary tree
void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

// inorder traversal of a binary tree
void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

// postorder traversal of a binary tree
void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

// find a binary tree with the given key
struct node* search(node ** tree, int key)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(key < (*tree)->data)
    {
        search(&((*tree)->left), key);
    }
    else if(key > (*tree)->data)
    {
        search(&((*tree)->right), key);
    }
    else if(key == (*tree)->data)
    {
        return *tree;
    }
}
