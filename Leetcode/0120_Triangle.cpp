#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// int Solve(int n, int index, int row, vector<vector<int>> &arr)
// {
//     if (row >= n)
//         return 0;
//     int first = Solve(n, index, row + 1, arr);
//     int second = Solve(n, index + 1, row + 1, arr);
//     return arr[row][index] + min(first, second);
// }
//
// int minimumTotal(vector<vector<int>> &triangle)
// {
//     int n = triangle.size();
//     return Solve(n, 0, 0, triangle);
// }

/*BETTER-1 MEMOIZATION*/
// int Solve(int n, int index, int row, vector<vector<int>> &arr, vector<vector<int>> &dp)
// {
//     if (row >= n)
//         return 0;
//     if (dp[row][index] != -1)
//         return dp[row][index];
//     int first = Solve(n, index, row + 1, arr, dp);
//     int second = Solve(n, index + 1, row + 1, arr, dp);
//     return dp[row][index] = arr[row][index] + min(first, second);
// }
//
// int minimumTotal(vector<vector<int>> &triangle)
// {
//     int n = triangle.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return Solve(n, 0, 0, triangle, dp);
// }

/*BETTER-2*/
// int minimumTotal(vector<vector<int>> &triangle)
// {
//     int n = triangle.size();
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     int k = 1;
//     for (int row = n - 1; row >= 0; row--)
//     {
//         for (int index = n - k; index >= 0; index--)
//         {
//             int first = dp[row + 1][index];
//             int second = dp[row + 1][index + 1];
//             dp[row][index] = triangle[row][index] + min(first, second);
//         }
//         k++;
//     }
//     return dp[0][0];
// }

/*OPTIMAL*/
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    int k = 1;
    for (int row = n - 1; row >= 0; row--)
    {
        for (int index = n - k; index >= 0; index--)
        {
            int first = next[index];
            int second = next[index + 1];
            curr[index] = triangle[row][index] + min(first, second);
        }
        next = curr;
        k++;
    }
    return curr[0];
}

int main()
{
    // Example 1
    vector<vector<int>> triangle1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle1) << endl; // 11

    // Example 2
    vector<vector<int>> triangle2 = {{-10}};
    cout << minimumTotal(triangle2) << endl; // -10

    // Example 3
    vector<vector<int>> triangle3 = {{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}};
    cout << minimumTotal(triangle3) << endl; // 14

    // Example 4
    vector<vector<int>> triangle4 = {{5}, {9, 6}, {4, 6, 8}, {0, 7, 1, 5}};
    cout << minimumTotal(triangle4) << endl; // 15
}
