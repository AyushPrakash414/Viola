#include<bits/stdc++.h>
using namespace std;
int main()
{
    int no_proccess;
    cout<<"Enter the No. of Proccess:";
    cin>>no_proccess;
    vector<int>pid(no_proccess);
    vector<int>arrival_time(no_proccess);
    vector<int>burst_time(no_proccess);
    cout<<"Enter all Proccess id First:";
    for (int i=0;i<no_proccess;i++)
    {
        cin>>pid[i];
    }
    cout<<"Enter all Arival_Time:";
    for (int i=0;i<no_proccess;i++)
    {
        cin>>arrival_time[i];
    }
    cout<<"Enter all Burst_Time First:";
    for (int i=0;i<no_proccess;i++)
    {
        cin>>burst_time[i];
    }

}