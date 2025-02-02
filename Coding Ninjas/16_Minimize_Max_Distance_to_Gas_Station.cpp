#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// double minimiseMaxDistance(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     vector<int> temp(n - 1, 0);
//     for (int gas = 1; gas <= k; gas++)
//     {
//         double maxVal = -1;
//         int maxIndex = 0;
//         for (int i = 1; i < n; i++)
//         {
//             double diff = arr[i] - arr[i - 1];
//             double secLength = diff / (double)(temp[i - 1] + 1);
//             if (secLength > maxVal)
//             {
//                 maxVal = secLength;
//                 maxIndex = i - 1;
//             }
//         }
//         temp[maxIndex]++;
//     }
//     double ans = -1;
//     for (int i = 1; i < n; i++)
//     {
//         double diff = arr[i] - arr[i - 1];
//         double secLength = diff / (double)(temp[i - 1] + 1);
//         ans = max(ans, secLength);
//     }
//     return ans;
// }

/*BETTER*/
// double minimiseMaxDistance(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     vector<int> temp(n - 1, 0);
//     priority_queue<pair<double, int>> pq;
//     for (int i = 0; i < n - 1; i++)
//         pq.push({arr[i + 1] - arr[i], i});
//     for (int gas = 1; gas <= k; gas++)
//     {
//         auto p = pq.top();
//         pq.pop();
//         int secInd = p.second;
//         temp[secInd]++;
//         double inidiff = arr[secInd + 1] - arr[secInd];
//         double newSecLen = inidiff / (double)(temp[secInd] + 1);
//         pq.push({newSecLen, secInd});
//     }
//     return pq.top().first;
// }

/*OPTIMAL*/
int gasRequired(long double dist, vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) // Checking if exactly equal eg- 1/0.5=2 but number in between =1 as 1/0.5 is perfect division
            numberInBetween--;
        cnt += numberInBetween;
    }
    return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxDiff = INT_MIN;
    for (int i = 0; i < n - 1; i++)
        maxDiff = max(maxDiff, arr[i + 1] - arr[i]);

    double start = 0, end = maxDiff;
    while (end - start > 1e-6)
    {
        double mid = (start + end) / 2.0;
        int cnt = gasRequired(mid, arr);
        if (cnt > k)
            start = mid;
        else
            end = mid;
    }
    return end;
}

int main()
{
    vector<int> arr1 = {1, 3, 6, 10};
    int k1 = 2;
    cout << "The minimized maximum distance with " << k1 << " additional gas stations is: " << minimiseMaxDistance(arr1, k1) << endl;

    vector<int> arr2 = {2, 6, 12, 16};
    int k2 = 3;
    cout << "The minimized maximum distance with " << k2 << " additional gas stations is: " << minimiseMaxDistance(arr2, k2) << endl;

    vector<int> arr3 = {7, 14, 21, 30};
    int k3 = 1;
    cout << "The minimized maximum distance with " << k3 << " additional gas station is: " << minimiseMaxDistance(arr3, k3) << endl;
}
