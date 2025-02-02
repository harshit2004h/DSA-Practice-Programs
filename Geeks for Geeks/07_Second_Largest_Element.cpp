#include <bits/stdc++.h>
using namespace std;
int getSecondLargest(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0 || n == 1)
        return -1;

    int temp = arr[0];
    int ans = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp)
        {
            ans = temp;
            temp = arr[i];
        }
        else if (arr[i] > ans && arr[i] != temp)
            ans = arr[i];
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 8, 4, 3, 4, 9, 5, 0};
    cout << "Answer is- " << getSecondLargest(arr);
}