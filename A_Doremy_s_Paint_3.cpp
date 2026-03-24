#include<bits/stdc++.h>
using namespace std;
bool check_distinct(vector<int>arr)
{
    map<int,int>mp;
    for (int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }

    if (mp.size()>2)
        return false;
    if (mp.size()==1)
        return true;
    auto it=mp.begin();
    int first=it->second;
    it++;
    int second=it->second;
    if (abs(first-second)<=1)
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
        bool distinct=check_distinct(arr);
        if(distinct)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}