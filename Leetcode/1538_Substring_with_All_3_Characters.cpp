#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int numberOfSubstrings(string str)
// {
//     int n = str.length();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int cntA = 0, cntB = 0, cntC = 0;
//         for (int j = i; j < n; j++)
//         {
//             if (str[j] == 'a')
//                 cntA++;
//             else if (str[j] == 'b')
//                 cntB++;
//             else
//                 cntC++;
//             if (cntA > 0 && cntB > 0 && cntC > 0)
//                 ans++;
//         }
//     }
//     return ans;
// }

/*BETTER*/
// int numberOfSubstrings(string str)
// {
//     int n = str.length();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> temp(3, 0);
//         for (int j = i; j < n; j++)
//         {
//             temp[str[j] - 'a'] = 1;
//             if (temp[0] + temp[1] + temp[2] == 3)
//             {
//                 ans += n - j;
//                 break;
//             }
//         }
//     }
//     return ans;
// }

/*OPTIMAL*/
int numberOfSubstrings(string str)
{
    int n = str.length();
    int ans = 0;
    vector<int> temp(3, -1);
    for (int i = 0; i < n; i++)
    {
        temp[str[i] - 'a'] = i;
        if (temp[0] >= 0 && temp[1] >= 0 && temp[2] >= 0)
            ans += min(temp[0], min(temp[1], temp[2])) + 1;
    }
    return ans;
}

int main()
{
    // Example 1
    string str1 = "abcabc";
    cout << numberOfSubstrings(str1) << endl; // 10

    // Example 2
    string str2 = "aaacb";
    cout << numberOfSubstrings(str2) << endl; // 3
}
