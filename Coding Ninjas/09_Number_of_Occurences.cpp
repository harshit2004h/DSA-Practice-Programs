#include <bits/stdc++.h>
using namespace std;
int count(vector<int> &nums, int n, int target)
{
    if (n == 0)
        return 0;
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (lb < n && nums[lb] == target)
        return ub - lb;
    else
        return 0;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    cout << "Count of target " << target << " is: " << count(nums, nums.size(), target) << endl;
}