#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int findIndex(int temp, vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//         if (temp == nums[i])
//             return i;
//     return -1;
// }
//
// vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
// {
//     vector<int> ans;
//     int n2 = nums2.size();
//     for (auto it : nums1)
//     {
//         int index = findIndex(it, nums2);
//         bool flag = true;
//         for (int i = index + 1; i < n2; i++)
//         {
//             if (nums2[i] > nums2[index])
//             {
//                 ans.push_back(nums2[i]);
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//             ans.push_back(-1);
//     }
//     return ans;
// }

/*OPTIMAL*/
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n2 = nums2.size();
    vector<int> temp(n2);
    unordered_map<int, int> nextGreaterMap;
    stack<int> s;

    for (int i = n2 - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums2[i])
            s.pop();

        nextGreaterMap[nums2[i]] = s.empty() ? -1 : s.top();
        s.push(nums2[i]);
    }

    vector<int> result;
    for (int num : nums1)
        result.push_back(nextGreaterMap[num]);

    return result;
}

int main()
{
    vector<int> nums1 = {4, 1, 2}; /*-1 3 -1*/
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = nextGreaterElement(nums1, nums2);
    for (int num : result)
        cout << num << " ";
    cout << endl;

    nums1 = {2, 4}; /*3 -1*/
    nums2 = {1, 2, 3, 4};
    result = nextGreaterElement(nums1, nums2);
    for (int num : result)
        cout << num << " ";
    cout << endl;
}
