#include <bits/stdc++.h>
using namespace std;
// /*BRUTE FORCE*/
// int rowWithMax1s(vector<vector<int>> &arr, int n, int m)
// {
//     int ans = 0, maxi = -1;
//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < m; j++)
//             if (arr[i][j] == 1)
//                 count++;
//         if (count > ans)
//         {
//             ans = count;
//             maxi = i;
//         }
//     }
//     return maxi;
// }

/*OPTIMAL*/
int rowWithMax1s(vector<vector<int>> &arr, int n, int m)
{
    int ans = 0, maxi = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int start = 0, end = m - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[i][mid] == 1)
            {
                count += end - mid + 1;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        if (count > ans)
        {
            ans = count;
            maxi = i;
        }
    }
    return maxi;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}};
    int n = arr.size();
    int m = arr[0].size();

    cout << "Row with maximum 1s: " << rowWithMax1s(arr, n, m) << endl;
}
