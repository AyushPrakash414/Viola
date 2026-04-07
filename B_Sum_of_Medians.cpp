#include<bits/stdc++.h>
using namespace std;
int Ayush (int n,int k,vector<int>arr)
{
    int count=0;
    for (int i=0;i<k;i++)
    {
        count+=arr[i];
    }
    return count;
}
int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        int n,k;
        cin>>n>>k;
        vector<int >arr(n*k,0);
        for (int i=0;i<n*k;i++)
        {
            cin>>arr[i];
        }
        if (n==2)
        {
            cout<<Ayush(n,k,arr)<<endl;
        }
        else{
            int position=arr.size()-(n-1);
            int count=0;
            for (int i=0;i<k;i++)
            {
                count+=arr[position];
                position-=n;
            }
            cout<<count<<endl;
        }
    }
}