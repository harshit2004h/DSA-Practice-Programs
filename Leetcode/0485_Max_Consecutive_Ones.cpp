#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &arr)
{
    int n = arr.size();
    int count = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            ans = max(ans, count);
        }
        else
            count = 0;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    cout << "Answer is- " << findMaxConsecutiveOnes(arr);
}