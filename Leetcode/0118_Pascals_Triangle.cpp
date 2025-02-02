#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// vector<vector<int>> generate(int n)
// {
//     vector<vector<int>> ans;
//     ans.push_back({1});
//     for (int i = 1; i < n; i++)
//     {
//         vector<int> temp;
//         temp.push_back(1);
//         for (int j = 1; j < ans[i - 1].size(); j++)
//             temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
//         temp.push_back(1);
//         ans.push_back(temp);
//     }
//     return ans;
// }

/*OPTIMAL*/
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp(i + 1, 1);
        long long res = 1;
        for (int j = 1; j < i; j++)
        {
            res = res * (i - j + 1);
            res = res / j;
            temp[j] = res;
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<vector<int>> ans = generate(5);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}