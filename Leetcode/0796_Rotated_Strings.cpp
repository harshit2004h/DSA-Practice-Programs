#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
        return false;
    string rotated = s;
    for (int i = 0; i < s.length(); i++)
    {
        if (rotated == goal)
            return true;

        char ch = rotated[0];
        rotated.erase(0, 1);
        rotated.push_back(ch);
    }
    return false;
}
int main()
{
    string s = "abcde", goal = "cdeab";
    if (rotateString(s, goal))
        cout << "The string can be rotated to match the goal." << endl;
    else
        cout << "The string cannot be rotated to match the goal." << endl;
}
