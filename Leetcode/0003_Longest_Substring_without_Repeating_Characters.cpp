#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int lengthOfLongestSubstring(string str)
// {
//     int n = str.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int len = 0;
//         vector<int> temp(256, 0);
//         for (int j = i; j < n; j++)
//         {
//             if (temp[str[j]] == 1)
//                 break;
//             len = j - i + 1;
//             ans = max(len, ans);
//             temp[str[j]] = 1;
//         }
//     }
//     return ans;
// }

/*OPTIMAL*/
int lengthOfLongestSubstring(string str)
{
    int n = str.size();
    vector<int> mpp(256, -1);
    int left = 0, right = 0;
    int len = 0;
    while (right < n)
    {
        if (mpp[str[right]] != -1)
            left = max(mpp[str[right]] + 1, left);

        mpp[str[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int main()
{
    // First example
    string str1 = "abcabcbb";
    cout << lengthOfLongestSubstring(str1) << endl; // 3

    // Second example
    string str2 = "bbbbb";
    cout << lengthOfLongestSubstring(str2) << endl; // 1
}
