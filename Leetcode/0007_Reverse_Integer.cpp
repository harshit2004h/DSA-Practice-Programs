#include <bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    bool flag = 0;
    int rev = 0;
    for (; x != 0; x /= 10)
    {
        if (rev > (INT_MAX / 10)) // Check if rev will overflow
            return 0;             // Return 0 if overflow is detected
        if (rev < (INT_MIN / 10)) // Check if rev will overflow
            return 0;             // Return 0 if overflow is detected

        rev = rev * 10 + (x % 10);
    }

    return rev;
}

int main()
{
    cout << "Answer is- " << reverse(1534236469) << endl;
    cout << "Answer is- " << reverse(-2147483648) << endl;
    cout << "Answer is- " << reverse(-2147) << endl;
}