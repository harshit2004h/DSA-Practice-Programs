#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// vector<int> findPrevSmaller(vector<int> &arr, int n)
// {
//     vector<int> ans(n, -1);
//     stack<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         while (!s.empty() && arr[s.top()] >= arr[i])
//             s.pop();
//         if (!s.empty())
//             ans[i] = s.top();
//         s.push(i);
//     }
//     return ans;
// }
//
// vector<int> findNextSmaller(vector<int> &arr, int n)
// {
//     vector<int> ans(n, n);
//     stack<int> s;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (!s.empty() && arr[s.top()] >= arr[i])
//             s.pop();
//         if (!s.empty())
//             ans[i] = s.top();
//         s.push(i);
//     }
//     return ans;
// }
//
// int largestRectangleArea(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> nextSmaller = findNextSmaller(arr, n);
//     vector<int> prevSmaller = findPrevSmaller(arr, n);
//     int ans = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int area = (nextSmaller[i] - prevSmaller[i] - 1) * arr[i];
//         ans = max(ans, area);
//     }
//     return ans;
// }

/*BETTER*/
// int largestRectangleArea(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> temp(n, -1);
//     int ans = INT_MIN;
//     stack<int> s;
//     for (int i = 0; i < n; i++)
//     {
//         while (!s.empty() && arr[s.top()] >= arr[i])
//         {
//             int area = arr[s.top()] * (i - temp[s.top()] - 1);
//             ans = max(ans, area);
//             s.pop();
//         }
//         if (!s.empty())
//             temp[i] = s.top();
//         s.push(i);
//     }
//     while (!s.empty())
//     {
//         int area = arr[s.top()] * (n - temp[s.top()] - 1);
//         ans = max(ans, area);
//         s.pop();
//     }
//     return ans;
// }

/*OPTIMAL*/
int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    int ans = INT_MIN;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            int height = arr[s.top()];
            s.pop();
            int pse = s.empty() ? -1 : s.top();
            int area = height * (i - pse - 1);
            ans = max(ans, area);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int height = arr[s.top()];
        s.pop();
        int pse = s.empty() ? -1 : s.top();
        int area = height * (n - pse - 1);
        ans = max(ans, area);
    }

    return ans;
}

int main()
{
    vector<int> arr1 = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(arr1) << endl; // 10

    vector<int> arr2 = {2, 4};
    cout << largestRectangleArea(arr2) << endl; // 4
}
