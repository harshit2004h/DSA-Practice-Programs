#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxLen = i + 1;
        else if (sumIndexMap.find(sum) != sumIndexMap.end())
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        else
            sumIndexMap[sum] = i;
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Answer is- " << getLongestZeroSumSubarrayLength(arr);
}