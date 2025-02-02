#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TLE*/
/*TIME COMPLEXITY- O(n^2)*/
// int characterReplacement(string str, int k)
// {
//     int n = str.length();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> hash(26, 0);
//         int maxFreq = 0;
//         for (int j = i; j < n; j++)
//         {
//             hash[str[j] - 'A']++;
//             maxFreq = max(maxFreq, hash[str[j] - 'A']);
//             int changes = (j - i + 1) - maxFreq;
//             if (changes <= k)
//                 ans = max(ans, j - i + 1);
//             else
//                 break;
//         }
//     }
//     return ans;
// }

/*BETTER- 1*/
/*TIME COMPLEXITY- O(2N*26)*/
// int characterReplacement(string str, int k)
// {
//     int n = str.length();
//     int l = 0, r = 0, maxFreq = 0, ans = 0;
//     vector<int> hash(26, 0);
//     while (r < n)
//     {
//         hash[str[r] - 'A']++;
//         maxFreq = max(maxFreq, hash[str[r] - 'A']);
//         while ((r - l + 1) - maxFreq > k)
//         {
//             hash[str[l] - 'A']--;
//             maxFreq = 0;
//             for (int i = 0; i < 26; i++)
//                 maxFreq = max(maxFreq, hash[i]);
//             l++;
//         }
//         if ((r - l + 1) - maxFreq <= k)
//             ans = max(ans, r - l + 1);
//         r++;
//     }
//     return ans;
// }

/*BETTER- 2*/
/*TIME COMPLEXITY- O(2N)*/
// int characterReplacement(string str, int k)
// {
//     int n = str.length();
//     int l = 0, r = 0, maxFreq = 0, ans = 0;
//     vector<int> hash(26, 0);
//     while (r < n)
//     {
//         hash[str[r] - 'A']++;
//         maxFreq = max(maxFreq, hash[str[r] - 'A']);
//         while ((r - l + 1) - maxFreq > k)
//         {
//             hash[str[l] - 'A']--;
//             l++;
//         }
//         if ((r - l + 1) - maxFreq <= k)
//             ans = max(ans, r - l + 1);
//         r++;
//     }
//     return ans;
// }

/*OPTIMAL*/
/*TIME COMPLEXITY- O(N)*/
int characterReplacement(string str, int k)
{
    int n = str.length();
    int l = 0, r = 0, maxFreq = 0, ans = 0;
    vector<int> hash(26, 0);
    while (r < n)
    {
        hash[str[r] - 'A']++;
        maxFreq = max(maxFreq, hash[str[r] - 'A']);

        if ((r - l + 1) - maxFreq > k)
        {
            hash[str[l] - 'A']--;
            l++;
        }
        else
            ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}

int main()
{
    // Example 1
    string str1 = "ABAB";
    int k1 = 2;
    cout << characterReplacement(str1, k1) << endl; // 4

    // Example 2
    string str2 = "AABABBA";
    int k2 = 1;
    cout << characterReplacement(str2, k2) << endl; // 4
}
