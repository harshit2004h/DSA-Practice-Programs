#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// bool canWePlace(vector<int> &arr, int dist, int cows)
// {
//     int n = arr.size();
//     int cntCows = 1;
//     int last = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] - last >= dist)
//         {
//             cntCows++;
//             last = arr[i];
//         }
//         if (cntCows >= cows)
//             return true;
//     }
//     return false;
// }

// int aggressiveCows(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     int limit = arr[n - 1] - arr[0];
//     for (int i = 1; i <= limit; i++)
//         if (canWePlace(arr, i, k) == false)
//             return (i - 1);
//     return limit;
// }

/*OPTIMAL*/
bool canWePlace(vector<int> &arr, int dist, int cows)
{
    int n = arr.size();
    int cntCows = 1;
    int last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last >= dist)
        {
            cntCows++;
            last = arr[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int start = 0, end = arr[n - 1] - arr[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (canWePlace(arr, mid, k) == false)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return end;
}

int main()
{
    vector<int> arr1 = {1, 2, 4, 8, 9};
    int k1 = 3;
    cout << "The largest minimum distance for k = " << k1 << " cows is: " << aggressiveCows(arr1, k1) << endl;

    vector<int> arr2 = {1, 3, 5, 7, 9};
    int k2 = 2;
    cout << "The largest minimum distance for k = " << k2 << " cows is: " << aggressiveCows(arr2, k2) << endl;

    vector<int> arr3 = {10, 20, 30, 40};
    int k3 = 2;
    cout << "The largest minimum distance for k = " << k3 << " cows is: " << aggressiveCows(arr3, k3) << endl;
}
