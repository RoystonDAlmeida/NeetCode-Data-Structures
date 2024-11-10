#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    
    // Constructor for assigning details of the new node
    ListNode(int value)
    {
        this->data=value;
        this->next=nullptr;
    }
};

// 1. Inserting at end
ListNode* insert_at_end(ListNode *head, int value){
    ListNode *newNode=new ListNode(value);
    if(head==nullptr)
    {
        head=newNode;
    }
    else{
        // Traverse till the end of the linked list  
        ListNode *cur=head;
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }
        cur->next=newNode;
    }
    return head;
}

// 2. Display a linked list 
void display_linked_list(ListNode *head)
{
    if(head==nullptr)
    {
        cout<<"\nLinked list is empty";
        return;
    }
    else
    {
        cout<<"\n";
        ListNode *cur=head;
        while(cur!=nullptr)
        {
            cout<<cur->data<<"\t";
            cur=cur->next;
        }
    }
}

//3. Finding the length of the linked List 
void find_length(ListNode *head)
{
    int count=0;
    if(head==nullptr)
    {
        cout<<"\nLinked list is empty";
        return;
    }
    else{
        ListNode *cur=head;
        while(cur!=nullptr)
        {
            count+=1;
            cur=cur->next;
        }
    }
    cout<<"\nLength of the linked list:"<<count;
}

//4. Searching for an element in a linked List
bool search_element(ListNode *head, int value)
{
    ListNode *cur=head;
    while(cur!=nullptr)
    {
        if(cur->data==value)
        {
            return true;
        }
        cur=cur->next;
    }
    return false;
}

// 5. Insert at beginning
ListNode* insert_at_beginning(ListNode *head, int value)
{
    ListNode *temp=new ListNode(value); 
    if(head==nullptr)
    {
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}

// 6. Insert at a specific position
ListNode* insert_at_position(ListNode *head, int pos, int data)
{
    ListNode *temp=new ListNode(data);
    if(pos==1)
    {
        // Insert at 1st position
        temp->next=head;
        head=temp;
    }

    int count=1;
    ListNode *prev=head;
    while(count<pos-1 && prev!=nullptr)
    {
        count++;
        prev=prev->next;
    }
    if(prev->next==nullptr)
    {
        cout<<"\n Invalid postion";
        return head;
    }
    temp->next=prev->next;
    prev->next=temp;
    return head;
}
// 7. Delete at beginning
ListNode* delete_at_beginning(ListNode *head)
{
    if(head==nullptr)
    {
        return NULL;
    }
    else
    {
        head=head->next;
    }
    return head;
}
// 8. Delete at end
ListNode* delete_at_end(ListNode *head)
{
    if(head==nullptr)
    {
        return NULL;
    }
    if(head->next==nullptr)
    {
        // If one node is present
        head=NULL;
    }
    else{
        ListNode* second_last=head;
        while(second_last->next->next!=nullptr)
        {
            second_last=second_last->next;
        }
        
        // Break the link between second last and last node
        second_last->next=nullptr;
    }
    return head;
}

// 9. Delete at position
ListNode* delete_at_position(ListNode *head, int pos)
{
    if(head==nullptr)
    {
        cout<<"\nLinked list is empty";
        return NULL;
    }
    if(pos==1)
    {
        head=head->next;
        return head;
    }
    else{
        int count=1;
        ListNode *prev=head;
        ListNode *cur=prev->next;
        while(count<pos-1 && cur->next!=nullptr){
            count++;
            prev=cur;
            cur=cur->next;
        }
        
        if(cur->next==nullptr)
        {
            cout<<"\nInvalid position";
        }
        else{
            prev->next=cur->next;
        }
    }
    return head;
}
int main()
{
    // Initialise a head pointer
    ListNode *head=nullptr;
    
    // Insert few nodes in the linked list 
    head = insert_at_end(head, 5);
    head=insert_at_end(head, 6);
    head=insert_at_end(head, 7);
    
    // Traverse the linked list
    display_linked_list(head);
    
    // Finding the length of the linked list
    find_length(head);
    
    // Searching for an element
    bool found=search_element(head,5);
    cout<<"\n"<<found<<"\n";
    
    // Insert at the beginning
    head=insert_at_beginning(head,10);
    display_linked_list(head);
    
    // Insert at position
    head=insert_at_position(head, 2, 11);
    display_linked_list(head);
    
    // Delete at beginning of the list
    head=delete_at_beginning(head);
    display_linked_list(head);
    
    // Delete at end of the list
    head=delete_at_end(head);
    display_linked_list(head);
    
    // Delete at position
    head=delete_at_position(head,2);
    display_linked_list(head);
    
    head=delete_at_position(head,1);
    display_linked_list(head);
    return 0;
}


