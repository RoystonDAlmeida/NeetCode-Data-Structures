#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int value)
    {
        data=value;
        next=nullptr;
    }
};
bool search_key(ListNode *head, int key)
{
    if(head==nullptr)
    {
        return NULL;
    }
    if(head->data==key)
    {
        return true;
    }
    return search_key(head->next,key);
}
int main()
{
    struct ListNode *head=new ListNode(14);
    head->next=new ListNode(18);
    head->next->next=new ListNode(22);
    int key=14;
    if(search_key(head,key))
    {
        cout<<"\nYes";
    }
    else{
        cout<<"\nNo";
    }
    return 0;
}
