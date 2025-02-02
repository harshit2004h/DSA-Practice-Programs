#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int singleNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     unordered_map<int, int> m;
//     for (int i = 0; i < n; i++)
//         m[nums[i]]++;
//     for (auto i : m)
//         if (i.second == 1)
//             return i.first;
//     return -1;
// }

/*BETTER- 1*/
// int singleNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     int ans = 0;
//     for (int i = 0; i < 32; i++)
//     {
//         int c = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (nums[j] & (1 << i))
//                 c++;
//         }
//         if (c % 3 == 1)
//             ans = ans | (1 << i);
//     }
//     return ans;
// }

/*BETTER- 2*/
// int singleNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     for (int i = 1; i < n; i += 3)
//     {
//         if (nums[i] != nums[i - 1])
//             return nums[i - 1];
//     }
//     return nums[n - 1];
// }

/*OPTIMAL*/
int singleNumber(vector<int> &nums)
{
    int ones = 0;
    int twos = 0;

    for (int num : nums)
    {
        ones ^= (num & ~twos);
        twos ^= (num & ~ones);
    }

    return ones;
}

int main()
{
    vector<int> nums1 = {2, 2, 3, 2};
    cout << "The single non-repeating number is: " << singleNumber(nums1) << endl;

    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << "The single non-repeating number is: " << singleNumber(nums2) << endl;

    vector<int> nums3 = {-2, -2, -2, -6};
    cout << "The single non-repeating number is: " << singleNumber(nums3) << endl;
}
