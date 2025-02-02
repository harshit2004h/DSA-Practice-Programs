#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// bool isAnagram(string str, string t)
// {
//     if (str.size() != t.size())
//         return false;
//     unordered_map<char, int> m1;
//     unordered_map<char, int> m2;
//     for (int i = 0; i < str.size(); i++)
//     {
//         m1[str[i]]++;
//         m2[t[i]]++;
//     }
//     for (int i = 0; i < str.size(); i++)
//         if (m1[str[i]] != m2[str[i]])
//             return false;
//     return true;
// }

/*OPTIMAL 1- USING HASHMAPS*/
// bool isAnagram(string str, string t)
// {
//     if (str.size() != t.size())
//         return false;
//     unordered_map<char, int> m;
//     for (int i = 0; i < str.size(); i++)
//     {
//         m[str[i]]++;
//         m[t[i]]--;
//     }
//     for (auto x : m)
//         if (x.second != 0)
//             return false;
//     return true;
// }

/*OPTIMAL 2- USING VECTORS*/
bool isAnagram(string str, string t)
{
    if (str.size() != t.size())
        return false;

    vector<int> v(26, 0);
    for (int i = 0; i < str.size(); i++)
    {
        v[str[i] - 'a']++;
        v[t[i] - 'a']--;
    }

    for (auto i : v)
        if (i != 0)
            return false;
    return true;
}

int main()
{
    string str = "anagram";
    string t = "nagaram";
    if (isAnagram(str, t))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;
}
