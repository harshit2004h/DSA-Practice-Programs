#include <bits/stdc++.h>
using namespace std;
int romanToInt(string str)
{
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (m[str[i]] < m[str[i + 1]])
            ans -= m[str[i]];
        else
            ans += m[str[i]];
    }
    return ans;
}

int main()
{
    string roman = "MCMLXXXVII";
    cout << "Integer value of " << roman << ": " << romanToInt(roman) << endl;
}
