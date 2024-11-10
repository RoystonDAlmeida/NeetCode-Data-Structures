#include<iostream>
#include<queue>

using namespace std;

class Stack{
    queue<int> q1,q2;
    public:
            void push(int item)
            {
                q2.push(item);
                while(!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                swap(q1,q2);
            }
            
            void pop()
            {
                if(q1.empty())
                {
                    cout<<"Stack is empty"<<endl;
                    return;
                }
                q1.pop();
            }
            int top()
            {
                if(q1.empty())
                {
                    cout<<"\nQueue is empty";
                    return 0;
                }
                return q1.front();
            }
            bool empty()
            {
                return q1.empty();
            }
};

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout<<"\nTop element:"<<stack.top();
    stack.pop();
    cout<<"\nTop element:"<<stack.top();
    stack.pop();
    cout<<"\nTop element:"<<stack.top();
    stack.pop();
    cout<<"\n Stack is empty?"<<stack.empty();
    return 0;
}
