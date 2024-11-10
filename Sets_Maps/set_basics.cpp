#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    
    for(auto it=mySet.begin();it!=mySet.end();it++)
    {
        cout<<*it<<"\t";
    }
    
    mySet.erase(20);
    
    for(int num:mySet)
    {
        cout<<num<<"\t";
    }
    return 0;
}
