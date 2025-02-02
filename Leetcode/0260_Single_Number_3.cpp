#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// vector<int> singleNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans;
//     unordered_map<int, int> m;
//     for (int i = 0; i < n; i++)
//         m[nums[i]]++;
//     for (auto i : m)
//         if (i.second == 1)
//             ans.push_back(i.first);
//     return ans;
// }

/*OPTIMAL*/
vector<int> singleNumber(vector<int> &nums)
{
    int n = nums.size();
    long long XOR = 0;
    for (int i = 0; i < n; i++)
        XOR = XOR ^ nums[i];

    long long temp = (XOR & (XOR - 1)) ^ XOR;
    int b1 = 0, b2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] & temp)
            b1 = b1 ^ nums[i];
        else
            b2 = b2 ^ nums[i];
    }
    return {b1, b2};
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1, 4};
    vector<int> result1 = singleNumber(nums1);
    cout << "The two single numbers are: " << result1[0] << " and " << result1[1] << endl;

    vector<int> nums2 = {7, 8, 9, 8, 7, 10};
    vector<int> result2 = singleNumber(nums2);
    cout << "The two single numbers are: " << result2[0] << " and " << result2[1] << endl;

    vector<int> nums3 = {15, 20, 25, 20, 15, 30};
    vector<int> result3 = singleNumber(nums3);
    cout << "The two single numbers are: " << result3[0] << " and " << result3[1] << endl;
}
