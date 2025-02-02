#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// int subarraysWithKDistinct(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         unordered_map<int, int> m;
//         for (int j = i; j < n; j++)
//         {
//             m[arr[j]] = 1;
//             if (m.size() == k)
//                 ans++;
//             else if (m.size() > k)
//                 break;
//         }
//     }
//     return ans;
// }

/*OPTIMAL*/
int Solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0, right = 0;
    int ans = 0;
    unordered_map<int, int> m;
    while (right < n)
    {
        m[arr[right]]++;
        while (m.size() > k)
        {
            m[arr[left]]--;
            if (m[arr[left]] == 0)
                m.erase(arr[left]);
            left++;
        }
        ans += right - left + 1;
        right++;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int> &arr, int k)
{
    return Solve(arr, k) - Solve(arr, k - 1);
}

int main()
{
    // Example 1
    vector<int> arr1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    cout << subarraysWithKDistinct(arr1, k1) << endl; // 7

    // Example 2
    vector<int> arr2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    cout << subarraysWithKDistinct(arr2, k2) << endl; // 3
}
