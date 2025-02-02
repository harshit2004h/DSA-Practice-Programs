#include <bits/stdc++.h>
using namespace std;

/*BRUTE FORCE*/
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//         for (int j = i + 1; j < n; j++)
//             for (int k = j + 1; k < n; k++)
//                 if (nums[i] + nums[j] + nums[k] == 0)
//                 {
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

/*BETTER*/
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashset;
//         for (int j = i + 1; j < n; j++)
//         {
//             int third = -(nums[i] + nums[j]);
//             if (hashset.find(third) != hashset.end())
//             {
//                 vector<int> temp = {nums[i], nums[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(nums[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

/*OPTIMAL 1*/
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> ans;
//     for (int i = 0; i < n - 2;)
//     {
//         int j = i + 1, k = n - 1;
//         while (j < k)
//         {
//             int sum = nums[i] + nums[j] + nums[k];
//             if (sum < 0)
//                 j++;
//             else if (sum > 0)
//                 k--;
//             else
//             {
//                 ans.push_back({nums[i], nums[j], nums[k]});
//                 while (j < k && nums[j] == nums[j + 1])
//                     j++;
//                 while (j < k && nums[k - 1] == nums[k])
//                     k--;
//                 j++;
//                 k--;
//             }
//         }
//         while (i < n - 2 && nums[i + 1] == nums[i])
//             i++;
//         i++;
//     }
//     return ans;
// }

/*OPTIMAL 2*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k + 1] == nums[k])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}