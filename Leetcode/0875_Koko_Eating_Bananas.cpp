#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int minEatingSpeed(vector<int> &arr, int h)
// {
//     int n = arr.size();
//     int maxEle = INT_MIN;
//     for (int i = 0; i < n; i++)
//         maxEle = max(maxEle, arr[i]);
//     for (int i = 1; i <= maxEle; i++)
//     {
//         int reqTime = 0;
//         for (int j = 0; j < n; j++)
//             reqTime += ceil((double)(arr[j]) / (double)(i));
//         if (reqTime <= h)
//             return i;
//     }
//     return maxEle;
// }

/*OPTIMAL*/
int minEatingSpeed(vector<int> &arr, int h)
{
    int n = arr.size();
    int maxEle = INT_MIN;

    for (int i = 0; i < n; i++)
        maxEle = max(maxEle, arr[i]);

    int start = 1, end = maxEle, mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        // check
        long long reqTime = 0;
        for (int i = 0; i < n; i++)
            reqTime += ceil((double)(arr[i]) / (double)(mid));

        if (reqTime <= h)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

int main()
{
    vector<int> arr = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum eating speed to finish in " << h << " hours: " << minEatingSpeed(arr, h) << endl;

    arr = {30, 11, 23, 4, 20};
    h = 5;
    cout << "Minimum eating speed to finish in " << h << " hours: " << minEatingSpeed(arr, h) << endl;
}
