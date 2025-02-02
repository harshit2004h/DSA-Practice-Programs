#include <bits/stdc++.h>
using namespace std;
/*BETTER*/
// void findLeftMax(vector<int> &arr, vector<int> &leftMax, int n)
// {
//     leftMax[0] = arr[0];
//     for (int i = 1; i < n; i++)
//         leftMax[i] = max(leftMax[i - 1], arr[i]);
// }
//
// void findRightMax(vector<int> &arr, vector<int> &rightMax, int n)
// {
//     rightMax[n - 1] = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//         rightMax[i] = max(rightMax[i + 1], arr[i]);
// }
//
// int trap(vector<int> &arr)
// {
//     int n = arr.size();
//     int ans = 0;
//     vector<int> leftMax(n);
//     vector<int> rightMax(n);
//     findRightMax(arr, rightMax, n);
//     findLeftMax(arr, leftMax, n);
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] < leftMax[i] && arr[i] < rightMax[i])
//             ans += min(leftMax[i], rightMax[i]) - arr[i];
//     }
//     return ans;
// }

/*OPTIMAL*/
int trap(vector<int> &arr)
{
    int n = arr.size();
    int leftMax = 0, rightMax = 0, ans = 0;

    for (int l = 0, r = n - 1; l < r;)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] < leftMax)
                ans += leftMax - arr[l];
            else
                leftMax = arr[l];
            l++;
        }
        else
        {
            if (arr[r] < rightMax)
                ans += rightMax - arr[r];
            else
                rightMax = arr[r];
            r--;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; /*6*/
    cout << trap(arr) << endl;
}
