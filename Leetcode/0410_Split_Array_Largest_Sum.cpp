#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int n, int m, int temp)
{
    int cntNum = 1, last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (last + arr[i] <= temp)
            last += arr[i];
        else
        {
            last = arr[i];
            cntNum++;
        }

        if (cntNum > m)
            return false;
    }
    return true;
}

int splitArray(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxEle = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxEle = max(maxEle, arr[i]);
        sum += arr[i];
    }

    int start = maxEle, end = sum;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, k, mid) == false)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

int main()
{
    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2;
    cout << "The minimum largest sum is: " << splitArray(arr, k) << endl;
}
