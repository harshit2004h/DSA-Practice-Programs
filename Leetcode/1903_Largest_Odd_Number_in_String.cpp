#include <bits/stdc++.h>
using namespace std;
string largestOddNumber(string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        int n = str[i] - '0';
        if (n % 2 != 0)
            return str.substr(0, i + 1);
    }
    return "";
}

int main()
{
    string str = "4206";
    cout << "Largest odd number: " << largestOddNumber(str) << endl;

    str = "35427";
    cout << "Largest odd number: " << largestOddNumber(str) << endl;
}
