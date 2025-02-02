#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr, int n, int x)
{
    int start = 0, end = n - 1;
    int mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

int upperBound(vector<int> &arr, int x, int n)
{
    int start = 0, end = n - 1;
    int mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] > x)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

int main()
{
    vector<int> arr = {-10, -3, 0, 1, 3, 3, 5, 8, 12, 15};
    int n = arr.size();
    int x = 3;

    cout << "Lower bound of " << x << " is at index: " << lowerBound(arr, n, x) << endl;
    cout << "Upper bound of " << x << " is at index: " << upperBound(arr, x, n) << endl;
}