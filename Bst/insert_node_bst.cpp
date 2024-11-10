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

Node* insertNode(Node *node, int key)
{
    if(node==nullptr)
    {
        // The left or right child does not exists
        return new Node(key);
    }
    
    if(node->data==key)
    {
        // Node is present with that value
        return node;
    }
    
    // Recur the left or right subtree depending on node's value
    if(node->data<key)
    {
        node->right=insertNode(node->right, key);
    }
    else
    {
        node->left=insertNode(node->left,key);
    }
    
    // Return the unchanged Node
    return node;
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
    Node *root=new Node(50);
    root=insertNode(root,30);
    root=insertNode(root,20);
    root=insertNode(root,40);
    root=insertNode(root,70);
    root=insertNode(root,60);
    root=insertNode(root,80);
    
    inOrder(root);
    return 0;
}
