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

bool searchDFS(Node *root, int key)
{
    if(root==nullptr)
    {
        //Leafnode is nullptr
        return false;
    }
    if(root->data==key)
    {
        return root;
    }
    
    bool left_res=searchDFS(root->left,key);
    bool right_res=searchDFS(root->right, key);
    
    return left_res || right_res;
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
    
    int key=6;
    if(searchDFS(firstNode,key))
    {
        cout<<"\n KEY is present";
    }
    else
    {
        cout<<"\nKey is not present";
    }
    return 0;
}
