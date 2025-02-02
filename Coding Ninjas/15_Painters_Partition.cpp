#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int n, int m, int temp)
{
    int cntPainters = 1, last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (last + arr[i] <= temp)
            last += arr[i];
        else
        {
            last = arr[i];
            cntPainters++;
        }

        if (cntPainters > m)
            return false;
    }
    return true;
}

int findLargestMinDistance(vector<int> &arr, int k)
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
    vector<int> arr1 = {10, 20, 30, 40};
    int k1 = 2;
    cout << "The largest minimum distance for k = " << k1 << " painters is: " << findLargestMinDistance(arr1, k1) << endl;

    vector<int> arr2 = {10, 30, 40, 50, 60};
    int k2 = 3;
    cout << "The largest minimum distance for k = " << k2 << " painters is: " << findLargestMinDistance(arr2, k2) << endl;

    vector<int> arr3 = {5, 10, 15, 20};
    int k3 = 2;
    cout << "The largest minimum distance for k = " << k3 << " painters is: " << findLargestMinDistance(arr3, k3) << endl;
}
