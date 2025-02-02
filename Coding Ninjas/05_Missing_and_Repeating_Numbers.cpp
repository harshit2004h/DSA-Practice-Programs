#include <bits/stdc++.h>
using namespace std;
/*BETTER*/
// vector<int> findMissingRepeatingNumbers(vector<int> arr)
// {
//     int n = arr.size();
//     vector<int> temp(n, 0);
//     for (int i = 0; i < n; i++)
//         temp[arr[i] - 1]++;
//     int P, Q;
//     for (int i = 0; i < n; i++)
//     {
//         if (temp[i] == 2)
//             P = i + 1;
//         if (temp[i] == 0)
//             Q = i + 1;
//     }
//     return {P, Q};
// }

/*OPTIMAL 1 - USING  MATHS*/
// vector<int> findMissingRepeatingNumbers(vector<int> arr)
// {
//     long long n = arr.size();
//     long long reqSum = (n * (n + 1)) / 2;
//     long long sum = 0;
//     long long req2Sum = (n * (n + 1) * (2 * n + 1)) / 6;
//     long long sum2 = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//         sum2 += ((long long)arr[i] * (long long)arr[i]);
//     }
//     long long diff1 = sum - reqSum;
//     long long diff2 = (sum2 - req2Sum) / diff1;
//     long long X = (diff1 + diff2) / 2;
//     long long Y = X - diff1;
//     return {(int)X, (int)Y};
// }

/*OPTIMAL 2 - USING XOR*/
vector<int> findMissingRepeatingNumbers(vector<int> arr)
{
    long long n = arr.size();
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num ^= arr[i];
        num ^= (i + 1);
    }

    int bitNo = 0;
    while (1)
    {
        if ((num & (1 << bitNo)) != 0)
            break;
        bitNo++;
    }

    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (1 << bitNo)) != 0)
            one ^= arr[i];
        else
            zero ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << bitNo)) != 0)
            one ^= i;
        else
            zero ^= i;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == zero)
            cnt++;
    }
    if (cnt == 2)
        return {zero, one};
    return {one, zero};
}

int main()
{
    vector<int> arr = {5, 23, 40, 19, 22, 37, 2, 9, 3, 12, 4, 45, 6, 46, 14, 34, 38, 20, 24, 44, 8, 7, 29, 21, 36, 28, 13, 25, 1, 32, 14, 42, 48, 27, 47, 30, 11, 17, 15, 18, 33, 10, 39, 41, 35, 16, 26, 31};
    vector<int> ans = findMissingRepeatingNumbers(arr);
    cout << ans[0] << " " << ans[1];
}