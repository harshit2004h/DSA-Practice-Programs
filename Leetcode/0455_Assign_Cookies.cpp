#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;
    while (j < s.size() && i < g.size())
    {
        if (g[i] <= s[j])
            i++;
        j++;
    }
    return i;
}

int main()
{
    // Example 1
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << findContentChildren(g1, s1) << endl; // 1

    // Example 2
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << findContentChildren(g2, s2) << endl; // 2

    // Example 3
    vector<int> g3 = {10, 9, 8, 7};
    vector<int> s3 = {5, 6, 7, 8};
    cout << findContentChildren(g3, s3) << endl; // 2
}
