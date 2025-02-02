#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>> &arr, vector<int> &s)
{
    int n = arr.size(), i = 0;
    vector<vector<int>> ans;

    // Left
    while (i < n && arr[i][1] < s[0])
    {
        ans.push_back(arr[i]);
        i++;
    }

    // Colliding
    while (i < n && arr[i][0] <= s[1])
    {
        s[0] = min(s[0], arr[i][0]);
        s[1] = max(s[1], arr[i][1]);
        i++;
    }
    ans.push_back(s);

    // Right
    while (i < n)
    {
        ans.push_back(arr[i]);
        i++;
    }
    return ans;
}

int main()
{
    // Example 1
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> result1 = insert(intervals1, newInterval1);
    for (auto &interval : result1)
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    cout << endl; // [1, 5] [6, 9]

    // Example 2
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> result2 = insert(intervals2, newInterval2);
    for (auto &interval : result2)
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    cout << endl; // [1, 2] [3, 10] [12, 16]

    // Example 3
    vector<vector<int>> intervals3 = {};
    vector<int> newInterval3 = {5, 7};
    vector<vector<int>> result3 = insert(intervals3, newInterval3);
    for (auto &interval : result3)
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    cout << endl; // [5, 7]

    // Example 4
    vector<vector<int>> intervals4 = {{1, 5}};
    vector<int> newInterval4 = {2, 3};
    vector<vector<int>> result4 = insert(intervals4, newInterval4);
    for (auto &interval : result4)
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    cout << endl; // [1, 5]
}
