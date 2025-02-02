#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int lengthOfLongestSubstring(string str)
// {
//     int n = str.length();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         unordered_map<char, int> m;
//         for (int j = i; j < n; j++)
//         {
//             m[str[j]] = 1;
//             if (m.size() > 2)
//                 break;
//             ans = max(ans, j - i + 1);
//         }
//     }
//     return ans;
// }

/*BETTER*/
// int lengthOfLongestSubstring(string str)
// {
//     int n = str.length();
//     int left = 0, right = 0, ans = 0;
//     unordered_map<char, int> m;
//     while (right < n)
//     {
//         m[str[right]]++;
//         while (m.size() > 2)
//         {
//             m[str[left]]--;
//             if (m[str[left]] == 0)
//                 m.erase(str[left]);
//             left++;
//         }
//         if (m.size() <= 2)
//             ans = max(ans, right - left + 1);
//         right++;
//     }
//     return ans;
// }

/*OPTIMAL*/
int lengthOfLongestSubstring(string str)
{
    int n = str.length();
    int left = 0, right = 0, ans = 0;
    unordered_map<char, int> m;
    while (right < n)
    {
        m[str[right]]++;
        if (m.size() > 2)
        {
            m[str[left]]--;
            if (m[str[left]] == 0)
                m.erase(str[left]);
            left++;
        }
        if (m.size() <= 2)
            ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main()
{
    // Example 1
    string str1 = "eceba";
    cout << lengthOfLongestSubstring(str1) << endl; // 3

    // Example 2
    string str2 = "aa";
    cout << lengthOfLongestSubstring(str2) << endl; // 2
}
