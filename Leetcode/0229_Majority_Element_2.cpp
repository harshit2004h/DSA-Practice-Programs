#include <bits/stdc++.h>
using namespace std;
// vector<int> majorityElement(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans;
//     unordered_map<int, int> m;
//     for (int i = 0; i < n; i++)
//     {
//         m[nums[i]]++;
//         if (m[nums[i]] == (n / 3) + 1)
//             ans.push_back(nums[i]);
//     }
//     return ans;
// }

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0, el1, el2;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && nums[i] != el2)
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != el1)
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
            cnt1++;
        else if (el2 == nums[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
    }

    vector<int> ans;
    if (cnt1 > (n / 3))
        ans.push_back(el1);
    if (cnt2 > (n / 3))
        ans.push_back(el2);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9, 2, 5, 5, 5, 5, 5, 5, 4, 7, 5, 1, 2, 22, 2, 2, 2, 2, 2};
    vector<int> ans = majorityElement(nums);

    for (auto i : ans)
        cout << i << " ";
}