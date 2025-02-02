#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// int totalFruit(vector<int> &arr)
// {
//     int n = arr.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         set<int> s;
//         int temp = 0;
//         for (int j = i; j < n; j++)
//         {
//             s.insert(arr[j]);
//             if (s.size() > 2)
//                 break;
//             temp++;
//             ans = max(ans, temp);
//         }
//     }
//     return ans;
// }

/*OPTIMAL*/
int totalFruit(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = 0;
    int ans = 0;
    unordered_map<int, int> m;
    while (right < n)
    {
        m[arr[right]]++;
        if (m.size() <= 2)
            ans = max(ans, right - left + 1);
        else
        {
            m[arr[left]]--;
            if (m[arr[left]] == 0)
                m.erase(arr[left]);
            left++;
        }
        right++;
    }
    return ans;
}

int main()
{
    // Example 1
    vector<int> arr1 = {1, 2, 1};
    cout << totalFruit(arr1) << endl; // 3

    // Example 2
    vector<int> arr2 = {0, 1, 2, 2};
    cout << totalFruit(arr2) << endl; // 3
}
