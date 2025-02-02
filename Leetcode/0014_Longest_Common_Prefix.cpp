#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &arr)
{
    if (arr.empty())
        return "";
    string pref = arr[0];
    int prefLen = pref.length();

    for (int i = 1; i < arr.size(); i++)
    {
        string str = arr[i];
        while (prefLen > str.length() || pref != str.substr(0, prefLen))
        {
            prefLen--;
            if (prefLen == 0)
                return "";
            pref = pref.substr(0, prefLen);
        }
    }
    return pref;
}

int main()
{
    vector<string> arr = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(arr) << endl;
}
