#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int> &nums, int k)
{
    int n = nums.size();
    int ans = 0, temp = k;
    vector<bool> visited(k + 1, false);

    for (int i = n - 1; temp > 0; i--)
    {
        if (nums[i] <= k && !visited[nums[i]])
        {
            visited[nums[i]] = true;
            temp--;
        }
        ans++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3}; /*3*/
    int k = 2;
    cout << minOperations(nums, k) << endl;

    nums = {2, 1}; /*2*/
    k = 2;
    cout << minOperations(nums, k) << endl;
}

