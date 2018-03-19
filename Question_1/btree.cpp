#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left =  NULL;
        temp->right = NULL;
        if(val != 0)
        {
            temp->data = val;
        }
        else{
            temp->data = NULL;
        }
        *tree = temp;
        return;
    }

    if((*tree)->left == NULL)
    {
        insert(&(*tree)->left, val);
    }
    else
    {
        insert(&(*tree)->right, val);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}
int main()
{   int n,i,j,value;
    cin>>n;
    node *root[n];
    node *tmp[n];
    root[n]= NULL;
    for(i = 0; i<n;i++){
        for(j = 0; j<n;j++){
            cin>>value;
            insert(&root[i],value);
        }
    }


    for(i =0 ;i<n;i++)
    {
        printf("In Order Display\n");
        print_inorder(root[i]);
    }

    return 0;
}
