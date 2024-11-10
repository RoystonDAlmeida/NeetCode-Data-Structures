#include<iostream>
#include<vector>
using namespace std;

vector<int> insertion_sort(vector<int> numbers)
{
    for(int i=1;i<numbers.size();i++)
    {
        // start from index 1, as 0th element is assumed to be nSorted
        int key=numbers[i];
        int j=i-1;
        while(j>=0 && numbers[j]>key)
        {
            // Shift elements by one postion ahead to make space for the sorted element at the correct position
            numbers[j+1]=numbers[j];
            j=j-1;
        }
        numbers[j+1]=key;
    }
    return numbers;
}

int main()
{
    vector<int> numbers={3,2,15,20,12};
    vector<int> result=insertion_sort(numbers);
    cout<<"\nSorted array:\n";
    for(int num:result)
    {
        cout<<num<<"\t";
    }
    return 0;
}
