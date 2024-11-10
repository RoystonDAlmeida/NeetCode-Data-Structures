#include<iostream>
using namespace std;

class Node
{
    public:
            int data;
            Node *left, *right;
            Node(int key)
            {
                this->data=key;
                this->left=this->right=nullptr;
            }
};

Node* getSuccessor(Node *root)
{
    // Initialise a current Node(V)
    Node *cur=root;
    
    // Re-initialise cur to its right node(R)
    cur=cur->right;
    
    while(cur!=nullptr && cur->left!=nullptr)
    {
        cur=cur->left;
    }
    
    return cur;
}
Node* delNode(Node *root, int x)
{
    if(root==nullptr)
    {
        // Base case
        return root;
    }
    
    // If key is to be searched in a subtree
    if(root->data<x)
    {
        root->right=delNode(root->right,x);
    }
    
    else if(root->data>x)
    {
        root->left = delNode(root->left,x);
    }
    
    else
    {
        // If the root node is same as x
        if(root->left==nullptr)
        {
            // Only right child is present
            Node *temp=root->right;
            delete root;
            return temp;
        }
        
        if(root->right==nullptr)
        {
            // Only left child is present
            Node *temp=root->left;
            delete root;
            return temp;
        }
        
        else
        {
            Node *suc=getSuccessor(root);
            root->data=suc->data;
            root->right=delNode(root->right, suc->data);
        }
    }
    return root;
}
void inOrder(Node *root)
{
    if(root!=nullptr)
    {
        inOrder(root->left);
        cout<<root->data<<"\t";
        inOrder(root->right);
    }
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->right->left=new Node(12);
    root->right->right=new Node(18);
    
    int x=15;
    root=delNode(root,x);
    inOrder(root);
    return 0;
}
