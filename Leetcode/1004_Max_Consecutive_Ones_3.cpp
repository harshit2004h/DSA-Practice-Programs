#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// int longestOnes(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int zeros = 0;
//         for (int j = i; j < n; j++)
//         {
//             if (nums[j] == 0)
//                 zeros++;
//             if (zeros <= k)
//             {
//                 int len = j - i + 1;
//                 ans = max(ans, len);
//             }
//             else
//                 break;
//         }
//     }
//     return ans;
// }

/*BETTER*/
/*TIME COMPLEXITY- O(2n)*/
// int longestOnes(vector<int> nums, int k)
// {
//     int n = nums.size();
//     int left = 0, right = 0;
//     int zeros = 0;
//     int ans = 0;
//     while (right < n)
//     {
//         if (nums[right] == 0)
//             zeros++;
//         while (zeros > k)
//         {
//             if (nums[left] == 0)
//                 zeros--;
//             left++;
//         }
//         if (zeros <= k)
//         {
//             int len = right - left + 1;
//             ans = max(ans, len);
//         }
//         right++;
//     }
//     return ans;
// }

/*OPTIMAL*/
/*TIME COMPLEXITY- */
int longestOnes(vector<int> nums, int k)
{
    int n = nums.size();
    int left = 0, right = 0;
    int zeros = 0;
    int ans = 0;
    while (right < n)
    {
        if (nums[right] == 0)
            zeros++;
        if (zeros > k)
        {
            if (nums[left] == 0)
                zeros--;
            left++;
        }
        if (zeros <= k)
        {
            int len = right - left + 1;
            ans = max(ans, len);
        }
        right++;
    }
    return ans;
}

int main()
{
    // First example
    vector<int> nums1 = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int k1 = 2;
    cout << longestOnes(nums1, k1) << endl; // 7

    // Second example
    vector<int> nums2 = {0, 0, 1, 1, 0, 1, 1, 0, 1};
    int k2 = 3;
    cout << longestOnes(nums2, k2) << endl; // 8
}
