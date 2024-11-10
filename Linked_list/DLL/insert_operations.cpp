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

ListNode* insert_at_beginning(ListNode *head, int value)
{
    ListNode *temp=new ListNode(value);
    temp->next=head;
    if(head!=nullptr)
    {
        head->prev=temp;
    }
    return temp;
}

ListNode* insert_at_postion(ListNode *head, int data, int pos)
{
    ListNode *new_node=new ListNode(data);
    if(pos==1)
    {
        // At first position
        new_node->next=head;
        head=new_node;
        return head;
    }
    else
    {
        ListNode *cur=head;
        for(int i=1;i<pos-1 && cur!=nullptr;++i)
        {
            cur=cur->next;
        }
        
        if(cur==nullptr)
        {
            cout<<"\nInvalid position";
            return NULL;
        }
        // Adjust the links
        new_node->prev=cur;
        new_node->next=cur->next;
        cur->next=new_node;
        
        if(new_node->next!=nullptr)
        {
            // The node added is not the last
            new_node->next->prev=new_node;
        }
        return head;
    }
}
ListNode* insert_at_end(ListNode *head, int value)
{
    ListNode *temp=new ListNode(value);
    if(head==nullptr)
    {
        head=temp;
    }
    else{
        ListNode *cur=head;
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
    }
    return head;
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
    
    // Insert an element at the beginning
    head=insert_at_beginning(head,0);
    cout<<"\nList after inserting\n";
    forward_traversal(head);
    
    // Insert an element at the end
    head=insert_at_end(head,5);
    cout<<"\nList after inserting\n";
    forward_traversal(head);
    
    // Insert an element at the position
    head=insert_at_postion(head, 2,4);
    cout<<"\nList after inserting:";
    forward_traversal(head);
    
    return 0;
}
