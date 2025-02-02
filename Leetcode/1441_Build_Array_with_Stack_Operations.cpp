#include <bits/stdc++.h>
using namespace std;
vector<string> buildArray(vector<int> &target, int n)
{
    int size = target.size();
    vector<string> ans;
    int temp = 0;
    for (int i = 1; temp < size; i++)
    {
        if (i == target[temp])
        {
            ans.push_back("Push");
            temp++;
        }
        else
        {
            ans.push_back("Push");
            ans.push_back("Pop");
        }
    }
    return ans;
}

int main()
{
    // Push Push Pop Push Push Push Push Pop Push
    vector<int> target = {1, 3, 4, 6};
    int n = 6;
    vector<string> result = buildArray(target, n);
    for (const auto &str : result)
        cout << str << " ";
    cout << endl;
}