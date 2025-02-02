#include <bits/stdc++.h>
using namespace std;
int maxDepth(string str)
{
    int ans = INT_MIN, balance = 0;
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(')
            balance++;
        else if (ch == ')')
            balance--;
        ans = max(balance, ans);
    }
    return ans;
}

int main()
{
    string str = "(1+(2*3)+((8)/4))+1";
    cout << "Maximum depth of parentheses: " << maxDepth(str) << endl;
}
