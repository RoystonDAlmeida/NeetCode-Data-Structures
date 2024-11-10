// Reverse a linked list 
#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *link;
    ListNode(int value)
    {
        data=value;
        link=nullptr;
    }
};

void display_list(ListNode *head)
{
    if(head==nullptr)
    {
        cout<<"\nList is empty\n";
        return;
    }
    ListNode *cur=head;
    while(cur!=nullptr)
    {
        cout<<cur->data<<"\t";
        cur=cur->link;
    }
}

ListNode* reverse_list(ListNode *head)
{
    ListNode *prev=nullptr, *cur=head,*next;
    while(cur!=nullptr)
    {
        // Store the next node after current
        next=cur->link;
        // Point previous to next node
        cur->link=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

int main(){
    ListNode *head=new ListNode(1);
    head->link=new ListNode(2);
    head->link->link=new ListNode(3);
    display_list(head);
    head=reverse_list(head);
    cout<<"\n Reverse linked list:\n"
    display_list(head);
    return 0;
}

