#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// void solve(vector<int> arr, vector<int> output, int i, vector<vector<int>> &ans)
// {
//     if (i >= arr.size())
//     {
//         ans.push_back(output);
//         return;
//     }
//     solve(arr, output, i + 1, ans); // Exclude
//     output.push_back(arr[i]);
//     solve(arr, output, i + 1, ans); // Include
// }
//
// vector<vector<int>> subsets(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     vector<int> output;
//     int i = 0;
//     solve(nums, output, i, ans);
//     return ans;
// }

/*OPTIMAL*/
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subsets = 1 << n;
    vector<vector<int>> ans;

    for (int i = 0; i < subsets; i++)
    {
        vector<int> output;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                output.push_back(nums[j]);
        ans.push_back(output);
    }
    return ans;
}

int main()
{
    vector<int> numsA = {1, 2, 3};
    vector<vector<int>> resultA = subsets(numsA);
    cout << "Subsets of {1, 2, 3}:\n";
    for (const auto &subset : resultA)
    {
        cout << "{";
        for (int x : subset)
            cout << x << " ";
        cout << "}\n";
    }

    vector<int> numsB = {4, 5};
    vector<vector<int>> resultB = subsets(numsB);
    cout << "\nSubsets of {4, 5}:\n";
    for (const auto &subset : resultB)
    {
        cout << "{";
        for (int x : subset)
            cout << x << " ";
        cout << "}\n";
    }

    vector<int> numsC = {};
    vector<vector<int>> resultC = subsets(numsC);
    cout << "\nSubsets of {}:\n";
    for (const auto &subset : resultC)
    {
        cout << "{";
        for (int x : subset)
            cout << x << " ";
        cout << "}\n";
    }
}
