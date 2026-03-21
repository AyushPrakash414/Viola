#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int test;
    cin>>test;
    while (test--)
    {
        int temp;
        cin>>temp;
        if (temp%3==0)
            cout<<"Second"<<endl;
        else
            cout<<"First"<<endl;
    }
}