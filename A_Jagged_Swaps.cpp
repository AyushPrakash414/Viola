#include<bits/stdc++.h>
using namespace std;
bool check_distinct(vector<int>arr)
{
    int size=arr.size();
    int x=(size*(size+1))/2;
    int y=accumulate(arr.begin(),arr.end(),0);
    if (x==y)
        return true;
    else    
        return false;
}
int main ()
{
    int test;
    cin>>test;
    while (test--)
    {
        int size;
        cin>>size;
        vector<int>arr(size,0);
        for (int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        if (arr[0]!=1)
        {
            cout<<"NO"<<endl;
        }   
        else{
            if (check_distinct(arr))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}