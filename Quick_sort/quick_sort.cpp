#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    // Choose the element at index 'high' as pivot element
    int pivot=arr[high];
    
    //Set the index i as the correct pivot element index
    int i=low-1;
    
    // Traverse the elements arr[low..high-1] so that smaller elements are on left side
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            // An element smaller than the pivot is found, swap
            i++;
            swap(arr[i],arr[j]);
        }
    }
    
    // Move pivot after smaller elements and return its position
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void quickSort(vector<int>& arr,int low, int high)
{
    if(low<high)
    {
        // Find the index of the pivot element and then sort left and right partition
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main()
{
    vector<int> arr={10,7,8,9,1,5};
    quickSort(arr,0,arr.size()-1);
    cout<<"\nSorted array is:\n";
    for(int num:arr)
    {
        cout<<num<<"\t";
    }
    return 0;
}
