#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        vector<int>arr(7,0);
        for (int i=0;i<7;i++)
            cin>>arr[i];
        int final=(accumulate(arr.begin(),arr.end(),0)-*max_element(arr.begin(),arr.end()))*-1;
        cout<<final+*max_element(arr.begin(),arr.end())<<endl;
    }
}