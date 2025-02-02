#include <bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<long> PrefixSum(n);
    PrefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
        PrefixSum[i] = PrefixSum[i - 1] + nums[i];

    int left = 0, right = 0, result = 0;
    while (right < n)
    {
        int size = right - left + 1;
        long original =
            PrefixSum[right] - (left > 0 ? PrefixSum[left - 1] : 0);

        while (size * (long)nums[right] > original + k)
        {
            left++;
            size = right - left + 1;
            original = PrefixSum[right] - PrefixSum[left - 1];
        }

        result = max(result, size);
        right++;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 4};
    cout << "Answer is- " << maxFrequency(nums, 5);
}