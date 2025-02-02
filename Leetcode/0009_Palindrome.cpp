#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int rev = 0, num = x;
    while (x != 0)
    {
        int r = x % 10;
        if (rev > (INT_MAX / 10)) // Check if rev will overflow
            return 0;             // Return 0 if overflow is detected
        if (rev < (INT_MIN / 10)) // Check if rev will overflow
            return 0;
        rev = rev * 10 + r;
        x /= 10;
    }
    if (rev == num)
        return true;
    return false;
}

int main()
{
    cout<<"Answer is- "<<isPalindrome(-121);
}