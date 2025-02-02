#include <bits/stdc++.h>
using namespace std;
int binarySearch(int index, int k, vector<int> &nums, vector<long> &PrefixSum)
{
    int target = nums[index];
    int left = 0;
    int right = index;

    int best = index;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        long count = index - mid + 1;
        long windowSum = count * target;
        long currSum = PrefixSum[index] - PrefixSum[mid] + nums[mid];

        int options = windowSum - currSum;

        if (options > k)
            left = mid + 1;
        else
        {
            best = mid;
            right = mid - 1;
        }
    }

    return index - best + 1;
}

int maxFrequency(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<long> PrefixSum(n);
    PrefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
        PrefixSum[i] = PrefixSum[i - 1] + nums[i];

    int result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, binarySearch(i, k, nums, PrefixSum));

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 4};
    cout << "Answer is- " << maxFrequency(nums, 5);
}