#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"\nFront element of the queue"<<q.front();
    cout<<"\n Back element of the queue"<<q.back();
    q.pop();
    cout<<"\nFront element of the queue"<<q.front();
    cout<<"\nQueue is empty?"<<q.empty();
    cout<<"\nSize of the queue"<<q.size();
    return 0;
}
