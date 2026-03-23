#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        string a,b;
        int x,y;
        cin>>x>>y;
        cin>>a>>b;
        int count=0;
        while (a.find(b)==string::npos)
        {
            if(count>=x*y)
            {
                count=-1;
                break;
            }
            a.append(a);
            count++;
        }
        cout<<count<<endl;
    }
}