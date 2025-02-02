#include <bits/stdc++.h>
using namespace std;
vector<int> superiorElements(vector<int> &arr)
{
    int n = arr.size();
    int biggest = arr[n - 1];
    vector<int> ans;
    ans.push_back(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > biggest)
        {
            biggest = arr[i];
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 7, 52, 8, 2, 4, 1, 1, 0};
    vector<int> ans = superiorElements(arr);

    for (auto i : ans)
        cout << i << " ";
}