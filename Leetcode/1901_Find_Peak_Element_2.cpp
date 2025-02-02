#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// Check all element for up, down, left, right
// Time Complexity-> O(4*n*m)
// Space Complexity-> O(1)

/*BETTER*/
// Find Max Element in the matrix
// Time Complexity-> O(n*m)      //Improves Only Worst Case complexity than previous and degrades best complexity and average complexity
// Space Complexity0> O(1)

/*OPTIMAL*/
// Time Complexity-> O(n*log(m))
// Space Complexity-> O(1)
vector<int> findPeakGrid(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    int start = 0, end = m - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int maxEle = INT_MIN, index;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][mid] > maxEle)
            {
                maxEle = arr[i][mid];
                index = i;
            }
        }

        int left = mid - 1 >= 0 ? arr[index][mid - 1] : -1;
        int right = mid + 1 < m ? arr[index][mid + 1] : -1;
        if (maxEle > left && maxEle > right)
            return {index, mid};

        if (maxEle < left)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return {0, 0};
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 3, 6, 5},
        {16, 41, 23, 22, 6},
        {15, 21, 20, 14, 13},
        {9, 12, 8, 7, 11},
        {10, 2, 5, 3, 1}};

    vector<int> peak = findPeakGrid(matrix);
    cout << "Peak element is at position: (" << peak[0] << ", " << peak[1] << ")" << endl;
}