#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// long long subArrayRanges(vector<int> &arr)
// {
//     int n = arr.size();
//     long long ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int largest = INT_MIN;
//         int smallest = INT_MAX;
//         for (int j = i+1; j < n; j++)
//         {
//             largest = max(largest, arr[j]);
//             smallest = min(smallest, arr[j]);
//             ans += (largest - smallest);
//         }
//     }
//     return ans;
// }

/*OPTIMAL*/
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

void findNextGreaterIndex(vector<int> &arr, vector<int> &ans, int n)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= arr[s.top()])
            s.pop();
        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = n;
        s.push(i);
    }
}

void findPrevGreaterIndex(vector<int> &arr, vector<int> &ans, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] > arr[s.top()])
            s.pop();
        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = -1;
        s.push(i);
    }
}

long long subArrayRanges(vector<int> &arr)
{
    int n = arr.size();
    long long ans = 0;

    vector<int> nextSmaller(n);
    vector<int> prevSmaller(n);
    vector<int> nextGreater(n);
    vector<int> prevGreater(n);

    findNextSmallerIndex(arr, nextSmaller, n);
    findPrevSmallerIndex(arr, prevSmaller, n);
    findNextGreaterIndex(arr, nextGreater, n);
    findPrevGreaterIndex(arr, prevGreater, n);

    for (int i = 0; i < n; i++)
    {
        long long minimum = (long long)(nextSmaller[i] - i) * (i - prevSmaller[i]) * arr[i];
        long long maximum = (long long)(nextGreater[i] - i) * (i - prevGreater[i]) * arr[i];
        ans = ans + (maximum - minimum);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4,-2,-3,4,1}; /*59*/
    cout << subArrayRanges(arr) << endl;
}
