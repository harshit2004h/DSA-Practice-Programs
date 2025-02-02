#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
// string minWindow(string str, string t)
// {
//     int n = str.length();
//     int minLen = INT_MAX, index = -1;
//     for (int i = 0; i < n; i++)
//     {
//         unordered_map<char, int> m;
//         int cnt = 0;
//         for (int j = 0; j < t.length(); j++)
//             m[t[j]]++;
//         for (int j = i; j < n; j++)
//         {
//             if (m[str[j]] > 0)
//                 cnt++;
//             m[str[j]]--;
//             if (cnt == t.length())
//             {
//                 if (j - i + 1 < minLen)
//                 {
//                     minLen = j - i + 1;
//                     index = i;
//                     break;
//                 }
//             }
//         }
//     }
//     return (index == -1) ? "" : str.substr(index, minLen);
// }

/*OPTIMAL*/
string minWindow(string str, string t)
{
    int n = str.length();
    unordered_map<char, int> m;
    for (int i = 0; i < t.length(); i++)
        m[t[i]]++;

    int left = 0, right = 0, cnt = 0;
    int minLen = INT_MAX, index = -1;
    while (right < n)
    {
        if (m[str[right]] > 0)
            cnt++;
        m[str[right]]--;

        while (cnt == t.length())
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                index = left;
            }

            m[str[left]]++;
            if (m[str[left]] > 0)
                cnt--;
            left++;
        }
        right++;
    }
    return (index == -1) ? "" : str.substr(index, minLen);
}

int main()
{
    // Example 1
    string str1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << minWindow(str1, t1) << endl; // "BANC"

    // Example 2
    string str2 = "a";
    string t2 = "a";
    cout << minWindow(str2, t2) << endl; // "a"

    // Example 3
    string str3 = "a";
    string t3 = "aa";
    cout << minWindow(str3, t3) << endl; // ""
}
