#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int n = matrix.size(), m = matrix[0].size();
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             if (matrix[i][j] == target)
//                 return true;
//     return false;
// }

/*BETTER*/
// bool binarySearch(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     int start = 0, end = n - 1;
//     while (start <= end)
//     {
//         int mid = (start + end) / 2;
//         if (nums[mid] == target)
//             return true;
//         else if (target > nums[mid])
//             start = mid + 1;
//         else
//             end = mid - 1;
//     }
//     return false;
// }

// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     for (int i = 0; i < n; i++)
//         if (matrix[i][0] <= target && target <= matrix[i][m - 1])
//             return binarySearch(matrix[i], target);
//     return false;
// }

/*OPTIMAL*/
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size(), c = matrix[0].size();
    int start = 0, end = (r * c) - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / c][mid % c];
        if (element == target)
            return true;
        else if (element < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 3;
    bool result = searchMatrix(matrix, target);
    cout << "Target " << target << (result ? " is found in the matrix." : " is not found in the matrix.") << endl;
}
