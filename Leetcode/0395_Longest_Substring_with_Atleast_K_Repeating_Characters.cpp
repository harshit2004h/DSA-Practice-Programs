#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
bool Solve(unordered_map<char, int> &m, int k)
{
    for (auto i : m)
        if (i.second < k)
            return false;
    return true;
}

int longestSubstring(string str, int k)
{
    int n = str.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> m;
        for (int j = i; j < n; j++)
        {
            m[str[j]]++;
            if (Solve(m, k))
                ans = max(ans, j - i + 1);
        }
    }
    return ans;
}