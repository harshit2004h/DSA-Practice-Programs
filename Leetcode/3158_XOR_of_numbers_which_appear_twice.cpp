#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int duplicateNumbersXOR(vector<int> &nums)
// {
//     int n = nums.size();
//     int ans = 0;
//     unordered_map<int, int> m;
//     for (int i = 0; i < n; i++)
//         m[nums[i]]++;
//     for (auto i : m)
//         if (i.second == 2)
//             ans = ans ^ i.first;
//     return ans;
// }

/*OPTIMAL*/
int duplicateNumbersXOR(vector<int> &nums)
{
    int ans = 0;
    long long seen = 0;
    for (int n : nums)
        if (seen & (1LL << n))
            ans ^= n;
        else
            seen |= 1LL << n;
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    cout << "The XOR of duplicate numbers is: " << duplicateNumbersXOR(nums1) << endl;

    vector<int> nums2 = {4, 5, 6, 4, 6, 7, 7};
    cout << "The XOR of duplicate numbers is: " << duplicateNumbersXOR(nums2) << endl;

    vector<int> nums3 = {10, 20, 20, 30, 30, 10};
    cout << "The XOR of duplicate numbers is: " << duplicateNumbersXOR(nums3) << endl;
}
