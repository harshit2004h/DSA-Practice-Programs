// Moore's Voting Algorithm
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int element;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count = 1;
        }
        else if (nums[i] == element)
            count++;
        else
            count--;
    }

    int c = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == element)
            c++;

    if (c > n / 2)
        return element;
    return -1;
}

int main()
{
    vector<int> nums = {6, 5, 5};
    cout << "Answer is- " << majorityElement(nums);
}