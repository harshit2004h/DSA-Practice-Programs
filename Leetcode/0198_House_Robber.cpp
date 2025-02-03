#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE-1 GIVES TLE*/
// int Solve(vector<int> &nums, int index)
// {
//     if (index >= nums.size())
//         return 0;
//     int ans = 0;
//     for (int i = index + 2; i < nums.size(); i++)
//         ans = max(ans, Solve(nums, i));
//     return nums[index] + ans;
// }
//
// int rob(vector<int> &nums)
// {
//     int ans = 0;
//     for (int i = 0; i < nums.size(); i++)
//         ans = max(ans, Solve(nums, i));
//     return ans;
// }

/*BRUTE FORCE-2 GIVES TLE*/
// int Solve(vector<int> &nums, int index)
// {
//     if (index >= nums.size())
//         return 0;
//     return max(nums[index] + Solve(nums, index + 2), Solve(nums, index + 1));
// }
// int rob(vector<int> &nums)
// {
//     return Solve(nums, 0);
// }

/*BETTER-1*/
// int Solve(vector<int> &nums, int index, vector<int> &dp)
// {
//     if (index >= nums.size())
//         return 0;
//     if (dp[index] != -1)
//         return dp[index];
//     int ans = 0;
//     for (int i = index + 2; i < nums.size(); i++)
//         ans = max(ans, Solve(nums, i, dp));
//     return dp[index] = nums[index] + ans;
// }
//
// int rob(vector<int> &nums)
// {
//     int ans = 0, n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> dp(n + 1, -1);
//         ans = max(ans, Solve(nums, i, dp));
//     }
//     return ans;
// }

/*BETTER-2*/
// int Solve(vector<int> &nums, int index, vector<int> &dp)
// {
//     if (index >= nums.size())
//         return 0;
//     if (dp[index] != -1)
//         return dp[index];
//     return dp[index] = max(nums[index] + Solve(nums, index + 2, dp), Solve(nums, index + 1, dp));
// }
//
// int rob(vector<int> &nums)
// {
//     vector<int> dp(nums.size(), -1);
//     return Solve(nums, 0, dp);
// }

/*MORE BETTER*/
// int rob(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n + 2, 0);
//     for (int i = n - 1; i >= 0; i--)
//         dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
//     return dp[0];
// }

/*OPTIMAL*/
int rob(vector<int> &nums)
{
    int n = nums.size();
    int prev = 0, curr = 0, next = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        prev = max(nums[i] + next, curr);
        next = curr;
        curr = prev;
        prev = nums[i];
    }
    return curr;
}

int main()
{
    // Example 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << rob(nums1) << endl; // 4

    // Example 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << rob(nums2) << endl; // 12

    // Example 3
    vector<int> nums3 = {5, 3, 4, 11, 2};
    cout << rob(nums3) << endl; // 16

    // Example 4
    vector<int> nums4 = {10, 2, 3, 20, 5};
    cout << rob(nums4) << endl; // 30
}
