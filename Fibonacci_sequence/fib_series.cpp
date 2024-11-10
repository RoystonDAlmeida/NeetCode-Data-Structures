#include<iostream>
using namespace std;

void fibonacci(int n)
{
    int first=0,second=1;
    if(n<1)
    {
        cout<<"Invalid number of terms\n";
        return;
    }
    else{
        cout<<first<<"\t"<<second<<"\t";
        if(n>2){
            int terms=n;
            int count=2;
            while(count<n)
            {
                int third=first+second;
                cout<<third<<"\t";
                first=second;
                second=third;
                count++;
            }
        }
    }
}

int main()
{
    int terms;
    cout<<"\nEnter the number of terms:";
    cin>>terms;
    fibonacci(terms);
    return 0;
}
