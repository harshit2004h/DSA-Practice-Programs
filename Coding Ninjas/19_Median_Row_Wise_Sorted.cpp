#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &arr, int m, int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
        cnt += upperBound(arr[i], x, n);
    return cnt;
}

int median(vector<vector<int>> &arr, int m, int n)
{
    int low = INT_MAX, high = INT_MIN;

    // point low and high to right elements:
    for (int i = 0; i < m; i++)
    {
        low = min(low, arr[i][0]);
        high = max(high, arr[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(arr, m, n, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    int m = 3, n = 3;
    cout << "The median is: " << median(arr, m, n) << endl;
}
