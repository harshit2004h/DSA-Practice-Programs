#include <bits/stdc++.h>
using namespace std;
vector<int> getRow(int n)
{
    vector<int> ans(n + 1, 1);
    long long res = 1;
    for (int i = 1; i < n; i++)
    {
        res = res * (n - i + 1);
        res = res / i;
        ans[i] = res;
    }
    return ans;
}

int main()
{
    vector<int> ans = getRow(6);
    for (auto i : ans)
        cout << i << " ";
}