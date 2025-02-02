#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int singleNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     unordered_map<int, int> m;
//     for (int i = 0; i < n; i++)
//         m[nums[i]]++;
//     for (auto i : m)
//         if (i.second == 1)
//             return i.first;
//     return -1;
// }

/*OPTIMAL*/
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (auto i : nums)
        ans = ans ^ i;
    return ans;
}

int main()
{
    vector<int> numsA = {4, 1, 2, 1, 2};
    cout << "The single non-repeating number is: " << singleNumber(numsA) << endl;

    vector<int> numsB = {2, 3, 5, 3, 2};
    cout << "The single non-repeating number is: " << singleNumber(numsB) << endl;

    vector<int> numsC = {7, 9, 7};
    cout << "The single non-repeating number is: " << singleNumber(numsC) << endl;
}
