#include <bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int a[], int N, int k)
{
    unordered_map<long long, int> prefixSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < N; i++)
    {
        sum += a[i];

        if (sum == k)
            maxLen = i + 1;

        if (prefixSumMap.find(sum - k) != prefixSumMap.end())
            maxLen = max(maxLen, i - prefixSumMap[sum - k]);

        if (prefixSumMap.find(sum) == prefixSumMap.end())
            prefixSumMap[sum] = i;
    }
    return maxLen;
}

int main()
{
    int a[] = {10, 5, 2, 7, 1, 9};
    int N = sizeof(a) / sizeof(a[0]);
    int k = 15;

    cout << "Answer is - " << lenOfLongSubarr(a, N, k) << endl;
}