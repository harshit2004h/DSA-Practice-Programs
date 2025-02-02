#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// int numberOfSubarrays(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int cntOdd = 0;
//         for (int j = i; j < n; j++)
//         {
//             if (arr[j] % 2 != 0)
//                 cntOdd++;
//             if (cntOdd == k)
//                 ans++;
//         }
//     }
//     return ans;
// }

/*BETTER*/
// int numberOfSubarrays(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     int left = 0, right = 0;
//     int cntOdd = 0, ans = 0;
//     int countLeft = 0;
//     while (right < n)
//     {
//         if (arr[right] % 2 != 0)
//             cntOdd++;
//         while (cntOdd > k)
//         {
//             if (arr[left] % 2 != 0)
//                 cntOdd--;
//             left++;
//         }
//         if (cntOdd == k)
//         {
//             countLeft = 0;
//             int tempLeft = left;
//             while (tempLeft < n && arr[tempLeft] % 2 == 0)
//             {
//                 countLeft++;
//                 tempLeft++;
//             }
//             countLeft++;
//             ans += countLeft;
//         }
//         right++;
//     }
//     return ans;
// }

/*OPTIMAL*/
int Solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0, right = 0;
    int ans = 0, sum = 0;
    while (right < n)
    {
        sum += arr[right] % 2;
        while (sum > k)
        {
            sum -= arr[left] % 2;
            left++;
        }
        ans += right - left + 1;
        right++;
    }
    return ans;
}

int numberOfSubarrays(vector<int> &arr, int k)
{
    return Solve(arr, k) - Solve(arr, k - 1);
}

int main()
{
    // Example 1
    vector<int> arr1 = {1, 1, 2, 1, 1};
    int k1 = 3;
    cout << numberOfSubarrays(arr1, k1) << endl; // 2

    // Example 2
    vector<int> arr2 = {2, 4, 6};
    int k2 = 1;
    cout << numberOfSubarrays(arr2, k2) << endl; // 0
}
