#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
            int data;
            Node *left, *right;
            Node(int key)
            {
                this->data=key;
                this->left=this->right=nullptr;
            }    
};

void BFStraversal(Node *root)
{
    if(root==nullptr)
    {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    cout<<"Before Insertion:"<<"\n";
    while(!q.empty())
    {
        Node *node=q.front();
        q.pop();
        cout<<node->data<<"\t";
        
        if(node->left!=nullptr)
        {
            q.push(node->left);
        }
        
        if(node->right!=nullptr)
        {
            q.push(node->right);
        }
        
    }
}

Node* insertNode(Node *root, int key)
{
    if(root==nullptr)
    {
        root=new Node(key);
        return root;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        
        if(temp->left==nullptr)
        {
            //No left child
            temp->left=new Node(key);
            break;
        }
        else{
            q.push(temp->left);
        }
        
        if(temp->right==nullptr)
        {
            //No right child
            temp->right=new Node(key);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
    return root;
}

int main()
{
    Node *firstNode=new Node(2);
    Node *secondNode=new Node(3);
    Node *thirdNode=new Node(4);
    Node *fourthNode=new Node(5);
    
    firstNode->left=secondNode;
    firstNode->right=thirdNode;
    secondNode->left=fourthNode;
    
    BFStraversal(firstNode);
    cout<<"After Insertion:"<<"\n";
    Node *root=insertNode(firstNode,6);
    BFStraversal(root);
    return 0;
}
