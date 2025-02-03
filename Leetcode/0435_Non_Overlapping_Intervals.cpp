#include <bits/stdc++.h>
using namespace std;
static bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), compare);

    int ans = 0;
    int prev = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] < arr[prev][1])
            ans++;
        else
            prev = i;
    }
    return ans;
}

int main()
{
    // Example 1
    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals1) << endl; // 1

    // Example 2
    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << eraseOverlapIntervals(intervals2) << endl; // 2

    // Example 3
    vector<vector<int>> intervals3 = {{1, 2}, {2, 3}};
    cout << eraseOverlapIntervals(intervals3) << endl; // 0

    // Example 4
    vector<vector<int>> intervals4 = {{0, 30}, {5, 10}, {15, 20}};
    cout << eraseOverlapIntervals(intervals4) << endl; // 2
}
