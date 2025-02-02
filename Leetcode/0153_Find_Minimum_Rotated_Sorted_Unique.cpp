#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL 1-*/
// int findMin(vector<int> &arr)
// {
//     int n = arr.size();
//     int start = 0, end = n - 1, mid = 0;
//     int ans = INT_MAX;
//     while (start <= end)
//     {
//         mid = start + (end - start) / 2;
//         if (arr[start] <= arr[mid])
//         {
//             ans = min(ans, arr[start]);
//             start = mid + 1;
//         }
//         else
//         {
//             ans = min(ans, arr[mid]);
//             end = mid - 1;
//         }
//     }
//     return ans;
// }

/*OPTIMAL 2-*/
int findMin(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1, mid = 0;
    int ans = INT_MAX;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[start] <= arr[end])
        {
            ans = min(ans, arr[start]);
            break;
        }

        if (arr[start] <= arr[mid])
        {
            ans = min(ans, arr[start]);
            start = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << "Minimum element in the array is: " << findMin(arr) << endl;

    arr = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element in the array is: " << findMin(arr) << endl;
}
