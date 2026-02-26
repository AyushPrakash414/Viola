#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;

    while(test--)
    {
        long long size;
        cin >> size;

        long double px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<long long> arr(size);

        for(int i = 0; i < size; i++)
            cin >> arr[i];

        // distance between points
        long double d = sqrt(
            (qx-px)*(qx-px) +
            (qy-py)*(qy-py)
        );

        long long sum =
            accumulate(arr.begin(), arr.end(), 0LL);

        long long maxi =
            *max_element(arr.begin(), arr.end());

        long long minReach =
            max(0LL, 2LL*maxi - sum);

        if(minReach <= d && d <= sum)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}