#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
/*BRUTE FORCE*/
// int sumSubarrayMins(vector<int> &arr)
// {
//     int n = arr.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int mini = arr[i];
//         for (int j = i; j < n; j++)
//         {
//             mini = min(mini, arr[j]);
//             ans = (ans + mini) % MOD;
//         }
//     }
//     return ans;
// }

/*BETTER*/
void findNextSmallerIndex(vector<int> &arr, vector<int> &ans, int n)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] <= arr[s.top()])
            s.pop();
        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = n;
        s.push(i);
    }
}

void findPrevSmallerIndex(vector<int> &arr, vector<int> &ans, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] < arr[s.top()])
            s.pop();
        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = -1;
        s.push(i);
    }
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    vector<int> nextSmaller(n);
    vector<int> prevSmaller(n);
    findNextSmallerIndex(arr, nextSmaller, n);
    findPrevSmallerIndex(arr, prevSmaller, n);
    for (int i = 0; i < n; i++)
    {
        long long contrib = (long long)(nextSmaller[i] - i) * (i - prevSmaller[i]) % MOD * arr[i] % MOD;
        ans = (ans + contrib) % MOD;
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4}; /*17*/
    cout << sumSubarrayMins(arr) << endl;
}
