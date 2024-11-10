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
    
    cout<<"Before Deletion:"<<"\n";
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

Node* deleteNode(Node *root, int key)
{
    if(root==nullptr)
    {
        //Root node is not defined
        return nullptr;
    }
    
    // Initialise an empty node for 'target'
    Node *target=nullptr;
    
    // Construct a queue to keep track of the target Node
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        
        if(temp->data==key)
        {
            // temp node data is equal to target
            target=temp;
        }
        
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    
    if(target==nullptr)
    {
        // Target node is not found 
        return nullptr;
    }
    
    // Keep track of the lastNode and lastParent
    pair<Node*, Node*> last={nullptr, nullptr};
    queue<pair<Node*, Node*>> q1;
    
    // Push the root node and its parent
    q1.push({root,nullptr});
    
    while(!q1.empty())
    {
        auto curr=q1.front();
        q1.pop();
        
        // Keep track of the curr Node
        last=curr;
        
        if(curr.first->left)
        {
            q1.push({curr.first->left,curr.first});
        }
        
        if(curr.first->right)
        {
            q1.push({curr.first->right, curr.first});
        }
    }
    
    // Fetch the lastNode and its parent
    Node *lastNode=last.first;
    Node *lastParent=last.second;
    
    // Replace target value with lastNode and delete lastNode
    if(lastParent)
    {
        target->data=lastNode->data;
        if(lastParent->left==lastNode)
        {
            lastParent->left=nullptr;
        }
        else
        {
            lastParent->right=nullptr;
        }
        delete lastNode;
    }
    else
    {
        delete lastNode;
        return nullptr;
    }
    return root;
}

int main()
{
    Node *firstNode=new Node(2);
    Node *secondNode=new Node(3);
    Node *thirdNode=new Node(4);
    Node *fourthNode=new Node(5);
    Node *fifthNode=new Node(6);
    
    firstNode->left=secondNode;
    firstNode->right=thirdNode;
    secondNode->left=fourthNode;
    secondNode->right=fifthNode;
    
    BFStraversal(firstNode);
    
    // Delete the node '3'
    Node *root=deleteNode(firstNode,2);
    cout<<"\n"<<"After deleting:"<<"\n";
    BFStraversal(root);
    return 0;
}
