#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL*/
string removeKdigits(string nums, int k)
{
    string ans = "";
    int n = nums.length();

    for (int i = 0; i < n; i++)
    {
        while (!ans.empty() && ans.back() > nums[i] && k > 0)
        {
            ans.pop_back();
            k--;
        }
        ans.push_back(nums[i]);
    }

    while (k > 0)
    {
        ans.pop_back();
        k--;
    }

    int i = 0;
    while (i < ans.size() && ans[i] == '0')
        i++;

    ans = ans.substr(i);
    return ans.empty() ? "0" : ans;
}

int main()
{
    string nums = "1432219";
    int k = 3;
    cout << removeKdigits(nums, k) << endl; // 1219

    nums = "10200";
    k = 1;
    cout << removeKdigits(nums, k) << endl; // 200

    nums = "10";
    k = 2;
    cout << removeKdigits(nums, k) << endl; // 0
}
