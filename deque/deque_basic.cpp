#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> q;
    q.push_back(10);
    q.push_front(20);
    
    for(int el:q)
    {
        int element=q.front();
        cout<<element<<"\t";
        q.pop_front();
    }
    return 0;
}
