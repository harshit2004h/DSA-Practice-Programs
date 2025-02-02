#include <bits/stdc++.h>
using namespace std;
/*BETTER*/
// int maxProduct(vector<int> &nums)
// {
//     int n = nums.size();
//     int ans = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int product = 1;
//         for (int j = i; j < n; j++)
//         {
//             product *= nums[j];
//             ans = max(ans, product);
//         }
//     }
//     return ans;
// }

/*OPTIMAL 1*/
int maxProduct(vector<int> &nums)
{
    int maxi = INT_MIN, prefix = 1, suffix = 1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix *= nums[i];
        suffix *= nums[n - i - 1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}

/*OPTIMAL 2 - KADANE'S ALGORITHM*/
// int maxProduct(vector<int> &nums)
// {
//     int prod1 = nums[0], prod2 = nums[0], result = nums[0];
//     for (int i = 1; i < nums.size(); i++)
//     {
//         int temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]});
//         prod2 = min({nums[i], prod1 * nums[i], prod2 * nums[i]});
//         prod1 = temp;
//         result = max(result, prod1);
//     }
//     return result;
// }

int main()
{
    vector<int> nums = {-2, 3, 4, -1, 0, -2, 9, 9, 4, 0, 4, 6, -1, 4};
    cout << "Answer is- " << maxProduct(nums);
}