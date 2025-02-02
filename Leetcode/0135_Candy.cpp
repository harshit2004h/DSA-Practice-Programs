#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int candy(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> right(n, -1);
//     vector<int> left(n, -1);
//     left[0] = 1, right[n - 1] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > arr[i - 1])
//             left[i] = left[i - 1] + 1;
//         else
//             left[i] = 1;
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (arr[i] > arr[i + 1])
//             right[i] = right[i + 1] + 1;
//         else
//             right[i] = 1;
//     }
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//         sum += max(left[i], right[i]);
//     return sum;
// }

/*BETTER*/
// int candy(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> left(n, 1);
//     left[0] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > arr[i - 1])
//             left[i] = left[i - 1] + 1;
//         else
//             left[i] = 1;
//     }
//     int right = 1, sum = max(1, left[n - 1]);
//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (arr[i] > arr[i + 1])
//             right = right + 1;
//         else
//             right = 1;
//         sum += max(left[i], right);
//     }
//     return sum;
// }

/*OPTIMAL*/
int candy(vector<int> &arr)
{
    int n = arr.size();
    int sum = 1, i = 1;
    while (i < n)
    {
        if (arr[i] == arr[i - 1])
        {
            sum++;
            i++;
            continue;
        }

        int peak = 1;
        while (i < n && arr[i] > arr[i - 1])
        {
            peak++;
            sum += peak;
            i++;
        }

        int down = 1;
        while (i < n && arr[i] < arr[i - 1])
        {
            sum += down;
            i++;
            down++;
        }

        if (down > peak)
            sum += down - peak;
    }
    return sum;
}

int main()
{
    // Example 1
    vector<int> ratings1 = {1, 0, 2};
    cout << candy(ratings1) << endl; // 5

    // Example 2
    vector<int> ratings2 = {1, 2, 2};
    cout << candy(ratings2) << endl; // 4

    // Example 3
    vector<int> ratings3 = {1, 3, 2, 2, 1};
    cout << candy(ratings3) << endl; // 7

    // Example 4
    vector<int> ratings4 = {1, 2, 3, 4, 5};
    cout << candy(ratings4) << endl; // 15
}
