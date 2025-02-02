#include <bits/stdc++.h>
using namespace std;
/*BETTER*/
// bool binarySearch(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     int start = 0, end = n - 1;
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;
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
//     for (int i = 0; i < n; i++)
//         if (binarySearch(matrix[i], target))
//             return true;
//     return false;
// }

/*OPTIMAL*/
bool searchMatrix(vector<vector<int>> &arr, int target)
{
    int n = arr.size(), m = arr[0].size();
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (arr[row][col] == target)
            return true;

        if (arr[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target = 5;
    bool result = searchMatrix(matrix, target);
    cout << "Target " << target << (result ? " is found in the matrix." : " is not found in the matrix.") << endl;
}
