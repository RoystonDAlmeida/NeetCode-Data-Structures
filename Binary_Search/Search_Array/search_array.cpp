#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>& arr, int low, int high, int x)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x)
        {
            return binary_search(arr,low,mid-1,x);
        }
        else{
            return binary_search(arr,mid+1,high,x);
        }
    }
    return -1;
}

int main()
{
    vector<int> arr={1,3,5,7,9};
    int result=binary_search(arr,0,arr.size()-1,10);
    if(result==-1)
    {
        cout<<"\nElement not found";
    }
    else{
        cout<<"\nElement found at index:"<<result;
    }
    return 0;
}
