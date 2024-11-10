#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v={1,4,5,6,7};
    cout<<*max_element(v.begin(),v.end());
    return 0;
}
