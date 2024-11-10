#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<float>& bucket)
{
    // Start from index '1' as element at index '0' is already Sorted
    for(int j=1;j<bucket.size();j++)
    {
        float key=bucket[j];
        int i=j-1;
        while(i>=0 && bucket[i]>key)
        {
            // At index 0
            bucket[i+1]=bucket[i];
            i--;
        }
        bucket[i+1]=key;
    }
}
void bucketSort(float *arr, int n)
{
    // Step 1: Create an array of size 'n'
    vector<float> b[n];
    
    //Step 2: Iterate over each element and insert in appropriate bucket
    for(int i=0;i<n;i++)
    {
        int index=n*arr[i];
        b[index].push_back(arr[i]);
    }
    
    //Step 3: Use insertion sort for each bucket
    for(int i=0;i<n;i++)
    {
        insertionSort(b[i]);
    }
    
    // Step 4: Concatenate sorted buckets 
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            arr[index]=b[i][j];
            index++;
        }
    }
    
    
}
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
