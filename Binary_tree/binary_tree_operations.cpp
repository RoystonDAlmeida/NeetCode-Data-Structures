#include<iostream>
#include<queue>
using namespace std;

// Declare members as public as 'left and right' have to be accessed by the object
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int key)
    {
        data=key;
        left=right=nullptr;
    }
};

void inOrderDFS(Node *node)
{
    if(node==nullptr)
    {
        return;
    }
    inOrderDFS(node->left);
    cout<<node->data<<"\t";
    inOrderDFS(node->right);
}

void preOrderDFS(Node *node)
{
    if(node==nullptr)
    {
        return;
    }
    cout<<node->data<<"\t";
    preOrderDFS(node->left);
    preOrderDFS(node->right);
}

void postOrderDFS(Node *node)
{
    if(node==nullptr)
    {
        return;
    }
    postOrderDFS(node->left);
    postOrderDFS(node->right);
    cout<<node->data<<"\t";
}

void LevelOrderBFS(Node *root)
{
    if(root==nullptr)
    {
        return;
    }
    
    // Declare a queue
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *node=q.front();
        q.pop();
        cout<<node->data<<"\t";
        if(node->left!=nullptr){q.push(node->left);}
        if(node->right!=nullptr){q.push(node->right);}
    }
}
int main()
{
    Node *root=new Node(2);
    Node *secondNode=new Node(3);
    Node *thirdNode=new Node(4);
    Node *fourthNode=new Node(5);
    root->left=secondNode;
    root->right=thirdNode;
    secondNode->left=fourthNode;
    cout<<"Inorder traversal:"<<"\n";
    inOrderDFS(root);
    cout<<"\n"<<"PreOrder traversal:"<<"\n";
    preOrderDFS(root);
    cout<<"\n"<<"PostOrder traversal:"<<"\n";
    postOrderDFS(root);
    cout<<"\n"<<"BFS traversal"<<"\n";
    LevelOrderBFS(root);
    return 0;
}
