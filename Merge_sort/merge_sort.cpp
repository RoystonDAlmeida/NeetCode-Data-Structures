#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& numbers, int left, int mid, int right)
{
    // Calculate the bounds for two sorted subarrays
    int n1=mid-left+1;
    int n2=right-mid;
    
    // Create two temp arrays 
    vector<int> L(n1),R(n2);
    
    for(int i=0;i<n1;i++)
    {
        L[i]=numbers[left+i];
    }
    
    for(int j=0;j<n2;j++)
    {
        R[j]=numbers[mid+1+j];
    }
    
    // Initialise the indexes for comparison
    int i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            numbers[k]=L[i];
            i++;
        }
        else
        {
            numbers[k]=R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements
    while(i<n1)
    {
        numbers[k]=L[i];
        k++;
        i++;
    }
    
    while(j<n2)
    {
        numbers[k]=R[j];
        k++;
        j++;
    }
}

void print_sorted(vector<int> &numbers)
{
    cout<<"Sorted array:\n";
    for(int num:numbers)
    {
        cout<<num<<"\t";
    }
}
void merge_sort(vector<int>& numbers, int low, int high)
{
    if(low>=high)
    {
        return;
    }
    int mid=(low+high)/2;
    merge_sort(numbers, low,mid);
    merge_sort(numbers,mid+1,high);
    merge(numbers,low,mid,high);
}

int main()
{
    vector<int> numbers={12,11,13,5,6,7};
    merge_sort(numbers,0,numbers.size()-1);
    print_sorted(numbers);
    return 0;
}
