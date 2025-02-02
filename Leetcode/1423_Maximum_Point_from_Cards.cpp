#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL*/
int maxScore(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = k - 1, right = 1;
    int leftSum = 0, rightSum = 0;

    for (int i = 0; i < k; i++)
        leftSum += arr[i];

    int ans = leftSum;
    for (int i = 0; i < k; i++)
    {
        leftSum -= arr[left--];
        rightSum += arr[n - right++];
        ans = max(ans, leftSum + rightSum);
    }

    return ans;
}

int main()
{
    // Example 1
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 1};
    int k1 = 3;
    cout << maxScore(arr1, k1) << endl; // 12

    // Example 2
    vector<int> arr2 = {2, 2, 2};
    int k2 = 2;
    cout << maxScore(arr2, k2) << endl; // 4
}
