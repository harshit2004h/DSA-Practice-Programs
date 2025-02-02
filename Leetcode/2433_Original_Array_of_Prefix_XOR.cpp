#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL- 1*/
// vector<int> findArray(vector<int> &pref)
// {
//     vector<int> ans;
//     ans.push_back(pref[0]);
//     int n = pref.size();
//     for (int i = 1; i < n; i++)
//         ans.push_back(pref[i] ^ pref[i - 1]);
//     return ans;
// }

/*OPTIMAL- 2*/
vector<int> findArray(vector<int> &pref)
{
    vector<int> ans;
    int temp = 0;
    for (auto i : pref)
    {
        ans.push_back(temp ^ i);
        temp = i;
    }
    return ans;
}

int main()
{
    /*5 7 2 3 5*/
    vector<int> pref1 = {5, 2, 0, 3, 6};
    vector<int> result1 = findArray(pref1);
    for (auto num : result1)
        cout << num << " ";
    cout << endl;

    /*1 2 4 8*/
    vector<int> pref2 = {1, 3, 7, 15};
    vector<int> result2 = findArray(pref2);
    for (auto num : result2)
        cout << num << " ";
    cout << endl;

    /*10 6 8 6*/
    vector<int> pref3 = {10, 12, 14, 8};
    vector<int> result3 = findArray(pref3);
    for (auto num : result3)
        cout << num << " ";
    cout << endl;
}
