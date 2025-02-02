#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     stack<int> s;
//     s.push(-1);
//     vector<int> ans(n);
//     for (int i = n - 1; i >= 0; i--)
//     {
//         int curr = arr[i];
//         while (s.top() != -1 && arr[s.top()] >= curr)
//         {
//             s.pop();
//         }
//         if (s.top() == -1)
//             ans[i] = n;
//         else
//             ans[i] = s.top();
//         s.push(i);
//     }
//     return ans;
// }
//
// vector<int> prevSmallerElement(vector<int> &arr, int n)
// {
//     stack<int> s;
//     s.push(-1);
//     vector<int> ans(n);
//     for (int i = 0; i < n; i++)
//     {
//         int curr = arr[i];
//         while (s.top() != -1 && arr[s.top()] >= curr)
//         {
//             s.pop();
//         }
//         ans[i] = s.top();
//         s.push(i);
//     }
//     return ans;
// }
//
// int largestRectangleArea(vector<int> &heights)
// {
//     int n = heights.size();
//     vector<int> prev(n);
//     prev = prevSmallerElement(heights, n);
//     vector<int> next(n);
//     next = nextSmallerElement(heights, n);
//     int area = -1;
//     for (int i = 0; i < n; i++)
//     {
//         int l = heights[i];
//         int b = next[i] - prev[i] - 1;
//         int newArea = l * b;
//         area = max(area, newArea);
//     }
//     return area;
// }
//
// int maximalRectangle(vector<vector<char>> &matrix)
// {
//     int maxArea = INT_MIN;
//     vector<int> height(matrix[0].size(), 0);
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = 0; j < height.size(); j++)
//         {
//             if (matrix[i][j] == '1')
//                 height[j]++;
//             else
//                 height[j] = 0;
//         }
//         maxArea = max(maxArea, largestRectangleArea(height));
//     }
//     return maxArea;
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

int maximalRectangle(vector<vector<char>> &matrix)
{
    int maxArea = INT_MIN;
    vector<int> height(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < height.size(); j++)
        {
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }
        maxArea = max(maxArea, largestRectangleArea(height));
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> matrix1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix1) << endl; // 6

    vector<vector<char>> matrix2 = {
        {'0', '1'},
        {'1', '0'}};
    cout << maximalRectangle(matrix2) << endl; // 1

    vector<vector<char>> matrix3 = {{'0'}};
    cout << maximalRectangle(matrix3) << endl; // 0
}
