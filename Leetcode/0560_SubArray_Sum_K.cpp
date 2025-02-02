#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> m;
    m[0] = 1;

    int preSum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += nums[i];
        count += m[preSum - k];
        m[preSum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << "Answer is- " << subarraySum(nums, 3);
}