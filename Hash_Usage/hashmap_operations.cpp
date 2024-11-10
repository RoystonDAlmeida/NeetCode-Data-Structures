#include<iostream>
#include<unordered_map>
using namespace std;

// HashTable is implemented using unordered_map
int main()
{
    unordered_map<string,int> mp;
    
    // Inserting elements into HashMap
    mp["Alice"]=35;
    mp["Bob"]=20;
    mp["Charlie"]=30;
    
    // Print elements of HashMap
    for(const auto &it:mp)
    {
        cout<<it.first<<" is "<<it.second<<" years old"<<endl;
    }
    
    // Check if Alice is present
    if(mp.find("Alice")!=mp.end())
    {
        cout<<"Alice is "<<mp["Alice"]<<" years old"<<endl;
    }
    else
    {
        cout<<"Alice is not present in the map";
    }
    
    // Delete an element by key
    mp.erase("Charlie");
    cout<<"\n";
    
    for(const auto &it:mp)
    {
        cout<<it.first<<" is "<<it.second<<" years old"<<endl;
    }
    return 0;
}
