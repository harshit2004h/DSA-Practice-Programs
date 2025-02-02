#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// vector<int> rearrangeArray(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> pos;
//     vector<int> neg;
//     for (int i = 0; i < n; i++)
//         if (nums[i] < 0)
//             neg.push_back(nums[i]);
//         else
//             pos.push_back(nums[i]);
//     int temp = 0;
//     for (int i = 0; i < n / 2; i++)
//     {
//         nums[temp++] = pos[i];
//         nums[temp++] = neg[i];
//     }
//     return nums;
// }

/*OPTIMAL*/
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int a = 0;
    int b = 1;
    for (auto i : nums)
    {
        if (i < 0)
        {
            ans[b] = i;
            b += 2;
        }
        else
        {
            ans[a] = i;
            a += 2;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for (int i : result)
        cout << i << " ";
    cout << endl;
}