#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// vector<int> nextGreaterElements(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         bool flag = false;
//         // Right Check
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[j] > nums[i])
//             {
//                 ans.push_back(nums[j]);
//                 flag = true;
//                 break;
//             }
//         }
//         if (flag)
//             continue;
//         // Left Check
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[j] > nums[i])
//             {
//                 ans.push_back(nums[j]);
//                 flag = true;
//                 break;
//             }
//         }
//         if (flag)
//             continue;
//         ans.push_back(-1);
//     }
//     return ans;
// }

/*BETTER*/
// vector<int> nextGreaterElements(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         bool flag = false;
//         for (int j = i; j < i + n; j++)
//         {
//             if (nums[j % n] > nums[i])
//             {
//                 ans.push_back(nums[j % n]);
//                 flag = true;
//                 break;
//             }
//         }
//         if (!flag)
//             ans.push_back(-1);
//     }
//     return ans;
// }

/*OPTIMAL*/
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp(n);
    stack<int> s;

    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        int index = i % n;
        while (!s.empty() && s.top() <= nums[index])
            s.pop();

        temp[index] = s.empty() ? -1 : s.top();
        s.push(nums[index]);
    }

    return temp;
}

int main()
{
    vector<int> nums = {1, 2, 1}; /*2 -1 2*/
    vector<int> result = nextGreaterElements(nums);

    for (int val : result)
        cout << val << " ";
    cout << endl;
}
    