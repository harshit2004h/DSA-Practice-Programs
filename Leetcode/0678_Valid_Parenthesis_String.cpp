#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// bool Solve(string str, int index, int cnt)
// {
//     if (cnt < 0)
//         return false;
//     if (index == str.size())
//         return cnt == 0;
//     if (str[index] == '(')
//         return Solve(str, index + 1, cnt + 1);
//     if (str[index] == ')')
//         return Solve(str, index + 1, cnt - 1);
//     return Solve(str, index + 1, cnt + 1) || Solve(str, index + 1, cnt - 1) || Solve(str, index + 1, cnt);
// }
//
// bool checkValidString(string str)
// {
//     return Solve(str, 0, 0);
// }

/*OPTIMAL*/
bool checkValidString(string str)
{
    int n = str.size();
    int min = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            min++;
            max++;
        }
        else if (str[i] == ')')
        {
            min--;
            max--;
        }
        else
        {
            min--;
            max++;
        }
        if (max < 0)
            return false;
        if (min < 0)
            min = 0;
    }

    return min == 0;
}

int main()
{
    // Example 1
    string str1 = "()";
    cout << checkValidString(str1) << endl; // true

    // Example 2
    string str2 = "(*)";
    cout << checkValidString(str2) << endl; // true

    // Example 3
    string str3 = "(*))";
    cout << checkValidString(str3) << endl; // true

    // Example 4
    string str4 = "(*)))";
    cout << checkValidString(str4) << endl; // false
}
