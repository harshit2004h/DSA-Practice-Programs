#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int start = 0, end = n - 1, mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] > target)
            end = mid - 1;
        else if (nums[mid] < target)
            start = mid + 1;
        else
            return mid;
    }
    return start;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << "Target found/inserted at index: " << searchInsert(nums, target) << endl;
    target = 2;
    cout << "Target found/inserted at index: " << searchInsert(nums, target) << endl;
}