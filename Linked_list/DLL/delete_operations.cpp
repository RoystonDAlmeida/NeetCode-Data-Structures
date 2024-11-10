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

ListNode* delete_at_beginning(ListNode *head)
{
    if(head==nullptr)
    {
        cout<<"Linked list is empty";
        return NULL;
    }
    ListNode* temp=head;
    head=head->next;
    if(head!=nullptr)
    {
        // head is not holding any value
        head->prev=nullptr;
    }
    delete temp;
    return head;
}

ListNode* delete_at_end(ListNode *head)
{
    if(head==nullptr)
    {
        cout<<"\nLinked list is empty";
        return NULL;
    }
    else if(head->next==nullptr)
    {
        delete head;
        return NULL;
    }
    else{
        ListNode *cur=head;
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }
        cur->prev->next=nullptr;
        delete cur;
        return head;
    }
}
int main()
{
    ListNode *head=new ListNode(1);
    ListNode *second=new ListNode(2);
    ListNode *third=new ListNode(3);
    
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    
    cout<<"\nOriginal list\n";
    forward_traversal(head);
    
    // Delete an element at the beginning 
    head=delete_at_beginning(head);
    cout<<"\nLinked list after deleting from beginning\n";
    forward_traversal(head);
    
    // Delete an element at the end 
    head=delete_at_end(head);
    cout<<"\nLinked list after deleting from end\n";
    forward_traversal(head);
    head=delete_at_end(head);
    cout<<"\nLinked list after deleting from end\n";
    forward_traversal(head);
    return 0;
}
