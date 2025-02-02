#include <bits/stdc++.h>
using namespace std;
/*ITERATIVE*/
// int search(vector<int> &nums, int target)
// {
//     int start = 0, end = nums.size() - 1;
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;
//         if (nums[mid] < target)
//             start = mid + 1;
//         else if (nums[mid] > target)
//             end = mid - 1;
//         else
//             return mid;
//     }
//     return -1;
// }

/*RECURSIVE*/
int Solve(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
        return mid;
    else if (target > nums[mid])
        return Solve(nums, mid + 1, end, target);
    else
        return Solve(nums, start, mid - 1, target);
}
int search(vector<int> &nums, int target)
{
    return Solve(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> nums = {-10, -3, 0, 1, 3, 5, 8, 12, 15};
    int target = 3;
    cout << "Answer is- " << search(nums, target) << endl;

    target = 7;
    cout << "Answer is- " << search(nums, target) << endl;
}