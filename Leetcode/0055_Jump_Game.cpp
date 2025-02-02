#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// bool Solve(vector<int> &nums, int index)
// {
//     if (index >= nums.size() - 1)
//         return true;
//     if (nums[index] == 0)
//         return false;
//     for (int i = 1; i <= nums[index]; i++)
//         if (Solve(nums, index + i))
//             return true;
//     return false;
// }
//
// bool canJump(vector<int> &nums)
// {
//     return Solve(nums, 0);
// }

/*BETTER- 1*/
// bool Solve(vector<int> &nums, int index, vector<int> &dp)
// {
//     if (index >= nums.size() - 1)
//         return true;
//     if (nums[index] == 0)
//         return false;
//     if (dp[index] != -1)
//         return dp[index];
//     for (int i = 1; i <= nums[index]; i++)
//         if (Solve(nums, index + i, dp))
//             return dp[index] = true;
//     return dp[index] = false;
// }
//
// bool canJump(vector<int> &nums)
// {
//     vector<int> dp(nums.size(), -1);
//     return Solve(nums, 0, dp);
// }

/*BETTER- 2*/
// bool canJump(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, false);
//     dp[n - 1] = true;
//     for (int index = n - 2; index >= 0; index--)
//     {
//         for (int i = 1; i <= nums[index] && index + i < n; i++)
//         {
//             if (dp[index + i])
//             {
//                 dp[index] = true;
//                 break;
//             }
//         }
//     }
//     return dp[0];
// }

/*OPTIMAL*/
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxIndex = 0;
    for (int i = 0; i < n && maxIndex >= i; i++)
        maxIndex = max(maxIndex, i + nums[i]);
    return maxIndex >= n - 1;
}

int main()
{
    // Example 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << canJump(nums1) << endl; // true

    // Example 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << canJump(nums2) << endl; // false

    // Example 3
    vector<int> nums3 = {2, 0, 0};
    cout << canJump(nums3) << endl; // true

    // Example 4
    vector<int> nums4 = {1, 2, 3, 4, 5};
    cout << canJump(nums4) << endl; // true
}
