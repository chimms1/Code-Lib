#include<iostream>

using namespace std;

typedef struct mytree
{
    int data;
    struct mytree* left=NULL;
    struct mytree* right=NULL;
}TREE;


void inorder(TREE* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

int main()
{
    TREE* root = new struct mytree;
    root->data = 10;
    
    root->left = new struct mytree;
    root->left->data = 5;
    
    root->right = new struct mytree;
    root->right->data = 7;
    
    root->right->left = new struct mytree;
    root->right->left->data = 3;
    
    root->left->left = new struct mytree;
    root->left->left->data = 4;
    
    root->left->right = new struct mytree;
    root->left->right->data = 2;
    
    root->left->left->left = new struct mytree;
    root->left->left->left->data = 1;
    
    root->left->left->right = new struct mytree;
    root->left->left->right->data = 15;
    
    
    inorder(root);
    cout<<"\n\n";
}
