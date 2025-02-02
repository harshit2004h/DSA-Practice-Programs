#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- USING VECTORS*/
// static bool cmp(pair<char, int> &a, pair<char, int> &b)
// {
//     return a.second > b.second;
// }

// string frequencySort(string str)
// {
//     vector<pair<char, int>> v(62);
//     for (int i = 0; i < 26; i++)
//     {
//         v[i] = {char('a' + i), 0};
//         v[i + 26] = {char('A' + i), 0};
//     }
//     for (int i = 0; i < 10; i++)
//         v[i + 52] = {char('0' + i), 0};
//     for (char ch : str)
//     {
//         if (islower(ch))
//             v[ch - 'a'].second++;
//         else if (isupper(ch))
//             v[ch - 'A' + 26].second++;
//         else if (isdigit(ch))
//             v[ch - '0' + 52].second++;
//     }
//     sort(v.begin(), v.end(), cmp);
//     string ans = "";
//     for (auto &p : v)
//     {
//         if (p.second > 0)
//             ans.append(p.second, p.first);
//     }
//     return ans;
// }

/*BETTER- USING PRIORITY QUEUE*/
// string frequencySort(string s)
// {
//     string ans = "";
//     unordered_map<char, int> m;
//     priority_queue<pair<int, char>> pq;
//     for (char c : s)
//         m[c]++;
//     for (auto x : m)
//         pq.push({x.second, x.first});
//     while (!pq.empty())
//     {
//         ans += string(pq.top().first, pq.top().second);
//         pq.pop();
//     }
//     return ans;
// }

/*OPTIMAL- USING BUCKET SORT*/
string frequencySort(string str)
{
    unordered_map<char, int> m;
    unordered_map<int, string> bucket;
    for (char ch : str)
        m[ch]++;
    // Fill the bucket with characters grouped by their frequencies
    for (auto p : m)
        bucket[p.second] += string(p.second, p.first);
    string ans = "";
    for (int i = str.size(); i > 0; i--)
        if (bucket.find(i) != bucket.end())
            ans += bucket[i];
    return ans;
}

int main()
{
    string str = "tree";
    cout << "Frequency sorted string: " << frequencySort(str) << endl;
}
