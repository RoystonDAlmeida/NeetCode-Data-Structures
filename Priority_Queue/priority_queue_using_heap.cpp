#include<iostream>
using namespace std;

// Declare Binary Heap as Array with 'size'
int H[100];
int size=-1;

int parent(int i)
{
    // Function to return the parent node index of child node index 'i'
    return (i-1)/2;
}

int leftChild(int i)
{
    // Function to return the index of left node of 'i'
    return ((2*i)+1);
}

int rightChild(int i)
{
    // Function to return the index of right node of 'i'
    return ((2*i)+2);
}

void shiftUp(int i)
{
    // Function to adjust heap elements with the latest 'size' index
    while(i>0 && H[parent(i)]<H[i])
    {
        // If the parent node value is smaller than its child, swap
        swap(H[parent(i)], H[i]);
        
        // Change the index 'i'
        i=parent(i);
    }
}

void shiftDown(int i)
{
    // Function to shift down an element in order to maintain heap property
    int maxIndex=i;
    
    // Get the index of the left child
    int l=leftChild(i);
    
    if(l<=size && H[l]>H[maxIndex])
    {
        // Check whether the left child has larger value
        maxIndex=l;
    }
    
    // Get the idnex of the right child
    int r=rightChild(i);
    
    if(r<=size && H[r]>H[maxIndex])
    {
        maxIndex=r;
    }
    
    if(maxIndex!=i)
    {
        // maxIndex has changed
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}
void insert(int p)
{
    // Function to insert the element 'i' into the heap
    size+=1;
    H[size]=p;
    
    // Shift Up to maintain heap property
    shiftUp(size);
}

int getMax()
{
    // Return the root node of the Queue
    return H[0];
}

int extractMax()
{
    int result=H[0];
    
    // Replace the root node with the leaf node
    H[0]=H[size];
    size=size-1;
    
    // Shift the new root node down to maintain heap property
    shiftDown(0);
    
    return result;
}

void changePriority(int i, int p)
{
    int oldp=H[i];
    H[i]=p;
    
    if(oldp<p)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}

void remove(int i)
{
    // Function to remove the element at index 'i'
    H[i]=getMax();
    
    // Since element at index 'i' is replaced with max, shift up  
    shiftUp(i);
    
    int result=extractMax();
}
int main()
{
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    int i=0;
    cout<<"\n Queue elements after insertion are:\n";
    while(i<=size)
    {
        cout<<H[i]<<"\t";
        i++;
    }
    i=0;
    cout<<"\n";
    cout<<"\nThe element with maximum priority:"<<getMax()<<"\n";
    
    // Extract the maximum element
    cout<<"\nQueue elements after extracting max element is:"<<extractMax()<<"\n";
    while(i<=size)
    {
        cout<<H[i]<<"\t";
        i++;
    }
    
    // Changing the priority of an element
    changePriority(2, 49); // Change element at index '2' to 49
    i=0;
    cout<<"\nQueue elements after changing priority of element is:\n";
    while(i<=size)
    {
        cout<<H[i]<<"\t";
        i++;
    }
    
    // Removing the element at a particular index
    remove(2);
    i=0;
    cout<<"\nQueue elements after removing element is:\n";
    while(i<=size)
    {
        cout<<H[i]<<"\t";
        i++;
    }
    
    return 0;
}
