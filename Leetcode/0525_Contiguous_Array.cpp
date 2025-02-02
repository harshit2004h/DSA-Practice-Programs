#include <bits/stdc++.h>
using namespace std;
int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    int countOne = 0, countZero = 0;
    int ans = 0;

    unordered_map<int, int> mp;
    mp[0] = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            countOne++;
        else
            countZero++;

        int diff = countOne - countZero;
        if (mp.find(diff) != mp.end())
            ans = max(ans, i - mp[diff]);
        else
            mp[diff] = i;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1};
    cout << "Answer is- " << findMaxLength(nums);
}