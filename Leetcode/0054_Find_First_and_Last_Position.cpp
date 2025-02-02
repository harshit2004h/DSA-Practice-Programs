#include <bits/stdc++.h>
using namespace std;
/*USING STL*/
// vector<int> searchRange(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     if (n == 0)
//         return {-1, -1};
//     int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//     int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
//     if (lb < n && nums[lb] == target)
//         return {lb, ub - 1};
//     else
//         return {-1, -1};
// }

/*USING PLAIN BINARY SEARCH*/
int lowerBound(vector<int> arr, int x, int n)
{
    int start = 0, end = n - 1;
    int mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

int upperBound(vector<int> &arr, int x, int n)
{
    int start = 0, end = n - 1;
    int mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] > x)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 0)
        return {-1, -1};

    int lb = lowerBound(nums, target, n);
    if (lb >= n)
        return {-1, -1};
    int ub = upperBound(nums, target, n);
    if (nums[lb] == target)
        return {lb, ub - 1};
    return {-1, -1};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> ans = searchRange(nums, 8);
    cout << ans[0] << " " << ans[1];
}