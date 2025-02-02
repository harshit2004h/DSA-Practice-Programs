#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (ans.back()[1] >= arr[i][0])
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        else
            ans.push_back(arr[i]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {2, 5}, {3, 4}};
    vector<vector<int>> ans = merge(arr);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}