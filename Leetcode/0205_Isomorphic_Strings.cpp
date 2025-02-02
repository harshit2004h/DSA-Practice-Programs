#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string str, string t)
{
    if (str.size() != t.size())
        return false;

    unordered_map<char, char> m, revm;
    for (int i = 0; i < str.size(); i++)
    {
        int ch1 = str[i];
        int ch2 = t[i];

        if (m.find(ch1) == m.end())
            m[ch1] = ch2;
        else if (m[ch1] != ch2)
            return false;

        // Check reverse
        if (revm.find(ch2) == revm.end())
            revm[ch2] = ch1;
        else if (revm[ch2] != ch1)
            return false;
    }
    return true;
}

int main()
{
    string str = "egg", t = "add";
    if (isIsomorphic(str, t))
        cout << "The strings are isomorphic." << endl;
    else
        cout << "The strings are not isomorphic." << endl;
}
