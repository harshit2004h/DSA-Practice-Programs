#include <bits/stdc++.h>
using namespace std;
string reverseWords(string str)
{
    str = str + " ";
    string ans = "", res = "";
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        res = res + ch;
        if (ch == ' ')
        {
            if (res != " ")
                ans = res + ans;
            res = "";
        }
    }
    ans.pop_back();
    return ans;
}

int main()
{
    string str = "Hello World from ChatGPT";
    cout << "Reversed words: " << reverseWords(str) << endl;
}
