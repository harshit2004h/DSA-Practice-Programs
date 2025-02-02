#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1, mid = 0;
    int ans = INT_MAX;
    int index = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[start] <= arr[mid])
        {
            if (ans > arr[start])
            {
                ans = arr[start];
                index = start;
            }
            start = mid + 1;
        }
        else
        {
            if (ans > arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }
            end = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    cout << "Array is rotated " << findKRotation(arr) << " times" << endl;

    arr = {7, 9, 11, 12, 5};
    cout << "Array is rotated " << findKRotation(arr) << " times" << endl;
}
