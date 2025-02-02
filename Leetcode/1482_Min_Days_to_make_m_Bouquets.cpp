#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int day, int m, int k)
{
    int n = arr.size(); // size of the array
    int cnt = 0;
    int noOfB = 0;

    // count the number of bouquets:
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
            cnt++;
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int minDays(vector<int> &arr, int m, int k)
{
    int n = arr.size();
    long long val = m * 1ll * k * 1ll;
    if (val > n)
        return -1;

    int maxEle = INT_MIN, minEle = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxEle = max(maxEle, arr[i]);
        minEle = min(minEle, arr[i]);
    }

    int start = minEle, end = maxEle;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, mid, m, k))
            end = mid - 1;

        else
            start = mid + 1;
    }
    return start;
}

int main()
{
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << "Minimum days to make " << m << " bouquets: " << minDays(arr, m, k) << endl;

    arr = {7, 7, 7, 7, 12, 7, 7};
    m = 2, k = 3;
    cout << "Minimum days to make " << m << " bouquets: " << minDays(arr, m, k) << endl;
}