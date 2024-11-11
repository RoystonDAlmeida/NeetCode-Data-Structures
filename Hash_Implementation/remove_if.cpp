#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isOdd(int n)
{
    return n%2!=0;
}

int main()
{
    vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    
    // Removing an element(remove-erase)
    // auto newEnd=remove(vec.begin(), vec.end(), 3);
    // Removing elements from the end
    // vec.erase(newEnd, vec.end());
    
    cout<<"\nElements of the vector:"<<endl;
    for(int num:vec)
    {
        cout<<num<<"\t";
    }
    
    auto newEnd=remove_if(vec.begin(), vec.end(),isOdd);
    
    // Erase the elements from new end
    vec.erase(newEnd, vec.end());
    
    cout<<"\nNew elements of the vector(even only)"<<endl;
    for(int num:vec)
    {
        cout<<num<<"\t";
    }
    return 0;
}
