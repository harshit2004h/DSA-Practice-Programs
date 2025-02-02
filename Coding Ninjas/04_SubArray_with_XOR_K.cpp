#include <bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector<int> nums, int b)
{
    int n = nums.size();
    unordered_map<int, int> m;
    m[0] = 1;

    int preSum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        preSum = preSum ^ nums[i];
        count += m[preSum ^ b];
        m[preSum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int b = 6;
    cout << "Answer is - " << subarraysWithSumK(nums, b) << endl;
}