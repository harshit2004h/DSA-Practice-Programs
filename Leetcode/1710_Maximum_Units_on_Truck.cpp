#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL-1*/
// static bool compare(vector<int> &a, vector<int> &b)
// {
//     return a[1] > b[1];
// }
//
// int maximumUnits(vector<vector<int>> &arr, int weight)
// {
//     sort(arr.begin(), arr.end(), compare);
//     int ans = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i][0] <= weight)
//         {
//             ans += arr[i][1] * arr[i][0];
//             weight -= arr[i][0];
//         }
//         else
//         {
//             ans += arr[i][1] * weight;
//             break;
//         }
//     }
//     return ans;
// }

/*OPTIMAL-2*/
bool static compartor(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>> &arr, int weight)
{
    sort(arr.begin(), arr.end(), &compartor);
    int res = 0;
    for (auto p : arr)
    {
        if (weight <= 0)
            break;

        int minAdded = min(p[0], weight);
        res = res + minAdded * p[1];
        weight = weight - p[0];
    }
    return res;
}

int main()
{
    // Example 1
    vector<vector<int>> arr1 = {{1, 3}, {2, 2}, {3, 1}};
    int weight1 = 4;
    cout << maximumUnits(arr1, weight1) << endl; // 8

    // Example 2
    vector<vector<int>> arr2 = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    int weight2 = 10;
    cout << maximumUnits(arr2, weight2) << endl; // 91

    // Example 3
    vector<vector<int>> arr3 = {{10, 20}, {5, 5}, {8, 10}};
    int weight3 = 15;
    cout << maximumUnits(arr3, weight3) << endl; // 250
}
