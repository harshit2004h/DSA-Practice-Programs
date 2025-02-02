#include <bits/stdc++.h>
using namespace std;
static bool compare(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

int Solve(vector<vector<int>> &v, int temp)
{
    int start = 0;
    int end = v.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid][0] > temp)
            end = mid - 1;
        else if (v[mid][0] < temp)
            start = mid + 1;
        else
            return v[mid][1];
    }
    return -1;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({nums[i], i});

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++)
    {
        int temp = target - v[i][0];
        int j = Solve(v, temp);
        if (j != -1 && j != v[i][1])
            return {v[i][1], j};
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = twoSum(nums, 9);

    cout << ans[0] << " " << ans[1];
}