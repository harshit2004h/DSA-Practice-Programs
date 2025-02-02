#include <bits/stdc++.h>
using namespace std;
/*USING RECUSION*/
// int maxSubArrayRec(vector<int> &nums, int i, int &globalMax)
// {
//     if (i == 0)
//     {
//         globalMax = nums[0];
//         return nums[0];
//     }
//     int currentMax = max(nums[i], maxSubArrayRec(nums, i - 1, globalMax) + nums[i]);
//     globalMax = max(globalMax, currentMax);
//     return currentMax;
// }
// int maxSubArray(vector<int> &nums)
// {
//     int globalMax = nums[0];
//     maxSubArrayRec(nums, nums.size() - 1, globalMax);
//     return globalMax;
// }

/*OPTIMAL*/
int maxSubArray(vector<int> &arr)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
}