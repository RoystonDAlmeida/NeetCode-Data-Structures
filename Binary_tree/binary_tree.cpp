#include<iostream>
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

int main()
{
    Node *root=new Node(2);
    Node *secondNode=new Node(3);
    Node *thirdNode=new Node(4);
    Node *fourthNode=new Node(5);
    root->left=secondNode;
    root->right=thirdNode;
    secondNode->left=fourthNode;
    return 0;
}
