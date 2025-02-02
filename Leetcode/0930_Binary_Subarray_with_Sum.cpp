#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// int numSubarraysWithSum(vector<int> &arr, int goal)
// {
//     int n = arr.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum == goal)
//                 ans++;
//         }
//     }
//     return ans;
// }

/*BETTER*/
// int numSubarraysWithSum(vector<int> &arr, int goal)
// {
//     int n = arr.size();
//     int left = 0, sum = 0, ans = 0;
//     unordered_map<int, int> count;
//     count[0] = 1;
//     for (int right = 0; right < n; ++right)
//     {
//         sum += arr[right];
//         if (count.find(sum - goal) != count.end())
//             ans += count[sum - goal];
//         count[sum]++;
//     }
//     return ans;
// }

/*OPTIMAL*/
int Solve(vector<int> &arr, int k)
{
    if (k < 0)
        return 0;
    int n = arr.size();
    int left = 0, right = 0;
    int cnt = 0, sum = 0;
    while (right < n)
    {
        sum += arr[right];
        while (sum > k)
        {
            sum -= arr[left];
            left++;
        }
        cnt += (right - left + 1);
        right++;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int> &arr, int k)
{
    return Solve(arr, k) - Solve(arr, k - 1);
}

int main()
{
    // Example 1
    vector<int> arr1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << numSubarraysWithSum(arr1, goal1) << endl; // 4

    // Example 2
    vector<int> arr2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << numSubarraysWithSum(arr2, goal2) << endl; // 15
}
