#include <bits/stdc++.h>
using namespace std;
int countDot(vector<char>arr)
{
    int ans=0;
    for (int i=0;i<arr.size();i++)
    {
        if (arr[i]=='.')
         ans++;
    }
    return ans;
}
int main ()
{
    int test,size;
    cin>>test;
    while (test--)
    {
        cin>>size;
        bool flag=false;
        vector<char>arr(size);
        for (int i=0;i<size;i++)
        {
            cin>>arr[i];
        }

        for (int i=2;i<size;i++)
        {
            if (arr[i]=='.'&&arr[i-1]=='.'&&arr[i-2]=='.')
                flag=true;
        }

        if (flag)
            cout<<2<<endl;
        else
            cout<<countDot(arr)<<endl;
        
    }
    return 0;
}