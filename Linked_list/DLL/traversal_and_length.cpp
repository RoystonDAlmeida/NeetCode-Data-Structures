#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *prev, *next;
    ListNode(int val)
    {
        data=val;
        prev=next=nullptr;
    }
};

void forward_traversal(ListNode *head)
{
    ListNode *cur=head;
    if(head==nullptr)
    {
        cout<<"Linked list is empty";
        return;
    }
    else{
        while(cur!=nullptr)
        {
            cout<<cur->data<<"\t";
            cur=cur->next;
        }
    }
}

void backward_traversal(ListNode *tail)
{
    ListNode *cur=tail;
    if(tail==nullptr)
    {
        cout<<"Linked list is empty";
        return;
    }
    else{
        while(cur!=nullptr)
        {
            cout<<cur->data<<"\t";
            cur=cur->prev;
        }
    }
}

int findLength(ListNode *head)
{
    int count=0;
    for(ListNode *cur=head;cur!=nullptr;cur=cur->next)
    {
        count++;
    }
    return count;
}
int main()
{
    ListNode *head=new ListNode(1);
    ListNode *second=new ListNode(2);
    ListNode *third=new ListNode(3);
    
    // Connect head, second and third
    head->next=second;
    second->prev=head;
    
    second->next=third;
    third->prev=second;
    
    cout<<"\nForward traversal:\n";
    forward_traversal(head);
    
    cout<<"\nBackward traversal:\n";
    backward_traversal(third);
    
    int length=findLength(head);
    cout<<"\nLength of the linked list:"<<length;
    return 0;
}
