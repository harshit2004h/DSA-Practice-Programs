#include <bits/stdc++.h>
using namespace std;
int Solve(vector<int> &arr, int index, vector<int> &dp)
{
    if (index >= arr.size() - 1)
        return 0;
    if (arr[index] == 0)
        return INT_MAX;

    if (dp[index] != -1)
        return dp[index];
    int ans = INT_MAX;
    for (int i = 1; i <= arr[index]; i++)
    {
        int temp = Solve(arr, index + i, dp);
        if (temp != INT_MAX)
            ans = min(ans, 1 + temp);
    }
    return dp[index] = ans;
}

int minJumps(vector<int> &arr)
{
    vector<int> dp(arr.size(), -1);
    int ans = Solve(arr, 0, dp);
    if (ans != INT_MAX)
        return ans;
    return -1;
}

int main()
{
    vector<int> arr = {0, 1, 4, 3, 2, 6, 7};
    cout << "Answer is- " << minJumps(arr);
}