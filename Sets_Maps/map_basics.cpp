#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int, std::string> mp;
    mp[1]="One";
    mp[2]="Second";
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<"=>"<<it->second<<"\t";
    }
    
    mp.erase(2);
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<"=>"<<it->second<<"\t";
    }
    return 0;
}
