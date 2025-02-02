#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// void Solve(vector<int> &nums, int index, int count, int &ans)
// {
//     if (index >= nums.size() - 1)
//     {
//         ans = min(ans, count);
//         return;
//     }
//     for (int i = 1; i <= nums[index]; i++)
//         Solve(nums, index + i, count + 1, ans);
// }
//
// int jump(vector<int> &nums)
// {
//     int ans = INT_MAX;
//     Solve(nums, 0, 0, ans);
//     return ans;
// }

/*BETTER- GIVES TLE*/
// void Solve(vector<int> &nums, int index, int count, int &ans, vector<int> &dp)
// {
//     if (index >= nums.size() - 1)
//     {
//         ans = min(ans, count);
//         return;
//     }
//     if (dp[index] != -1 && count >= dp[index])
//         return;
//     dp[index] = count;
//     for (int i = 1; i <= nums[index]; i++)
//         Solve(nums, index + i, count + 1, ans, dp);
// }
//
// int jump(vector<int> &nums)
// {
//     int n = nums.size(), ans = INT_MAX;
//     vector<int> dp(n, -1);
//     Solve(nums, 0, 0, ans, dp);
//     return ans;
// }

/*BETTER-2*/
// int jump(vector<int> &nums)
// {
//     int n = nums.size();
//     if (n <= 1)
//         return 0;
//     vector<int> dp(n, INT_MAX);
//     dp[0] = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 1; j <= nums[i] && i + j < n; j++)
//         {
//             dp[i + j] = min(dp[i + j], dp[i] + 1);
//         }
//     }
//     return dp[n - 1];
// }

/*OPTIMAL*/
int jump(vector<int> &nums)
{
    int jump = 0, n = nums.size();
    int right = 0, left = 0;
    while (right < n - 1)
    {
        int far = 0;
        for (int i = left; i <= right; i++)
            far = max(i + nums[i], far);
        left = right + 1;
        right = far;
        jump++;
    }
    return jump;
}

int main()
{
    // Example 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << jump(nums1) << endl; // 2

    // Example 2
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << jump(nums2) << endl; // 2

    // Example 3
    vector<int> nums3 = {1, 2, 3};
    cout << jump(nums3) << endl; // 2

    // Example 4
    vector<int> nums4 = {1, 1, 1, 1};
    cout << jump(nums4) << endl; // 3
}
