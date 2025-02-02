#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int kDistinctChars(int k, string &str)
// {
//     int n = str.length();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         unordered_map<char, int> m;
//         for (int j = i; j < n; j++)
//         {
//             m[str[j]] = 1;
//             if (m.size() > k)
//                 break;
//             ans = max(ans, j - i + 1);
//         }
//     }
//     return ans;
// }

/*BETTER*/
// int kDistinctChars(int k, string &str)
// {
//     int n = str.length();
//     int left = 0, right = 0, ans = 0;
//     unordered_map<char, int> m;
//     while (right < n)
//     {
//         m[str[right]]++;
//         while (m.size() > k)
//         {
//             m[str[left]]--;
//             if (m[str[left]] == 0)
//                 m.erase(str[left]);
//             left++;
//         }
//         if (m.size() <= k)
//             ans = max(ans, right - left + 1);
//         right++;
//     }
//     return ans;
// }

/*OPTIMAL*/
int kDistinctChars(int k, string &str)
{
    int n = str.length();
    int left = 0, right = 0, ans = 0;
    unordered_map<char, int> m;
    while (right < n)
    {
        m[str[right]]++;
        if (m.size() > k)
        {
            m[str[left]]--;
            if (m[str[left]] == 0)
                m.erase(str[left]);
            left++;
        }
        if (m.size() <= k)
            ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main()
{
    // Example 1
    string str1 = "eceba";
    int k1 = 2;
    cout << kDistinctChars(k1, str1) << endl; // 3

    // Example 2
    string str2 = "aa";
    int k2 = 1;
    cout << kDistinctChars(k2, str2) << endl; // 2
}
