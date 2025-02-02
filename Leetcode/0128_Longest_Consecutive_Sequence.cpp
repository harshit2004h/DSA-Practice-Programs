#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int biggest = 1;
    unordered_set<int> s;

    for (auto i : nums)
        s.insert(i);

    for (auto i : s)
    {
        if (s.find(i - 1) == s.end())
        {
            int cnt = 1;
            int x = i;
            while (s.find(x + 1) != s.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            biggest = max(biggest, cnt);
        }
    }
    return biggest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Answer is- " << longestConsecutive(nums);
}