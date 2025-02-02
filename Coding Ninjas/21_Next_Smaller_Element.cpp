#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     vector<int> ans(n, -1);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 ans[i] = arr[j];
//                 break;
//             }
//         }
//     }
//     return ans;
// }

/*OPTIMAL*/
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] <= s.top())
            s.pop();
        if (!s.empty())
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 2, 1, 5, 3}; /*2 1 -1 3 -1*/
    vector<int> result = nextSmallerElement(arr, arr.size());

    for (int val : result)
        cout << val << " ";
    cout << endl;
}
