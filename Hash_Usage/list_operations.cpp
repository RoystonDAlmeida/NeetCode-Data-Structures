#include<iostream>
#include<list>
using namespace std;

// List is a non-sequential data structure containing nodes with 3 fields(address of prev node, data, address of next node)

int main()
{
    list<int> myList;
    
    // Adding elements at the last
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    
    // Adding element at the front
    myList.push_front(0);
    
    cout<<"\nElements of a list:\n";
    for(int num:myList)
    {
        cout<<num<<"\t";
    }
    
    // Removing front and last element of the list
    myList.pop_front();
    myList.pop_back();
    
    cout<<"\nFirst element of the list:"<<myList.front()<<endl;
    cout<<"\nLast element of the list:"<<myList.back()<<endl;
    
    // Reverse of the list
    myList.reverse();
    cout<<"\nElements of the list after reversing:\n";
    for(int num:myList)
    {
        cout<<num<<"\t";
    }
    
    // Sorting of the list(ascending order)
    myList.sort();
    cout<<"\nElements of the list after sorting:\n";
    for(int num:myList)
    {
        cout<<num<<"\t";
    }
    
    // Inserting an element in a list
    myList.insert(myList.begin(),5);    //myList.insert(<iterator>, value)
    cout<<"\nElements of the list after inserting:\n";
    for(int num:myList)
    {
        cout<<num<<"\t";
    }
    
    myList.remove(20);
    cout<<"\nElements of the list after removing:\n";
    for(int num:myList)
    {
        cout<<num<<"\t";
    }
    
    return 0;
}
