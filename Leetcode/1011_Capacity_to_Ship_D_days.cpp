#include <bits/stdc++.h>
using namespace std;
int shipWithinDays(vector<int> &arr, int days)
{
    int n = arr.size();
    int maxEle = INT_MIN, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxEle = max(maxEle, arr[i]);
    }

    int start = maxEle, end = sum;
    while (start < end)
    {
        int mid = start + (end - start) / 2;

        int requiredDays = 1, temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (temp + arr[i] > mid)
            {
                requiredDays++;
                temp = 0;
            }
            temp += arr[i];
        }

        if (requiredDays <= days)
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    cout << "Minimum capacity to ship within " << days1 << " days is: " << shipWithinDays(arr1, days1) << endl;

    vector<int> arr2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    cout << "Minimum capacity to ship within " << days2 << " days is: " << shipWithinDays(arr2, days2) << endl;

    vector<int> arr3 = {1, 2, 3, 1, 1};
    int days3 = 4;
    cout << "Minimum capacity to ship within " << days3 << " days is: " << shipWithinDays(arr3, days3) << endl;
}
