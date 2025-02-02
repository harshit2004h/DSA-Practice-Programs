#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int n, int m, int temp)
{
    int cntBooks = 1, last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (last + arr[i] <= temp)
            last += arr[i];
        else
        {
            last = arr[i];
            cntBooks++;
        }

        if (cntBooks > m)
            return false;
    }
    return true;
}

/*BRUTE FORCE*/
// int findPages(vector<int> &arr, int n, int m)
// {
//     if (n < m)
//         return -1;
//     int maxEle = INT_MIN, sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         maxEle = max(maxEle, arr[i]);
//         sum += arr[i];
//     }
//     for (int i = maxEle; i <= sum; i++)
//     {
//         if (isPossible(arr, n, m, i))
//             return i;
//     }
//     return -1;
// }

/*OPTIMAL*/
int findPages(vector<int> &arr, int n, int m)
{
    if (n < m)
        return -1;
    int maxEle = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxEle = max(maxEle, arr[i]);
        sum += arr[i];
    }

    int start = maxEle, end = sum;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid) == false)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

int main()
{
    vector<int> arr1 = {12, 34, 67, 90};
    int n1 = arr1.size();
    int m1 = 2;
    cout << "The minimum number of pages for m = " << m1 << " students is: " << findPages(arr1, n1, m1) << endl;

    vector<int> arr2 = {10, 20, 30, 40};
    int n2 = arr2.size();
    int m2 = 2;
    cout << "The minimum number of pages for m = " << m2 << " students is: " << findPages(arr2, n2, m2) << endl;

    vector<int> arr3 = {15, 17, 20};
    int n3 = arr3.size();
    int m3 = 2;
    cout << "The minimum number of pages for m = " << m3 << " students is: " << findPages(arr3, n3, m3) << endl;
}
