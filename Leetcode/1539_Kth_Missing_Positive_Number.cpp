#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int findKthPositive(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] <= k)
//             k++;
//         else
//             break;
//     }
//     return k;
// }

/*OPTIMAL*/
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            start = mid + 1;
        else
            end = mid - 1;
    }

    int ans = start + k;
    return ans;
}

int main()
{
    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "The " << k1 << "th missing positive number is: " << findKthPositive(arr1, k1) << endl;

    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "The " << k2 << "th missing positive number is: " << findKthPositive(arr2, k2) << endl;

    vector<int> arr3 = {5, 6, 7, 8, 9};
    int k3 = 1;
    cout << "The " << k3 << "th missing positive number is: " << findKthPositive(arr3, k3) << endl;
}
