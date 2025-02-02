#include <bits/stdc++.h>
using namespace std;
int missingNumber1(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i : nums)
        sum += i;

    int max_sum = (n * (n + 1)) / 2;
    return max_sum - sum;
}

int missingNumber2(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> temp(n + 1, false);

    for (auto i : nums)
        temp[i] = true;

    for (int i = 0; i <= n; i++)
        if (temp[i] == false)
            return i;
    return -1;
}

int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Answer is- " << missingNumber1(nums);
}