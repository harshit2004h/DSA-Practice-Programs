#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num)
{
    vector<pair<int, string>> v{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    string ans;

    for (auto i : v)
    {
        if (num == 0)
            break;

        while (num >= i.first)
        {
            ans += i.second;
            num -= i.first;
        }
    }
    return ans;
}

int main()
{
    int num = 1987;
    cout << "Roman numeral for " << num << ": " << intToRoman(num) << endl;
}
