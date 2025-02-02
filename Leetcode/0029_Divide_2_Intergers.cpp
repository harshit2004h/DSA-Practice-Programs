#include <bits/stdc++.h>
using namespace std;
/*CHEATING 😉*/
// int divide(int dividend, int divisor)
// {
//     if (dividend == INT_MIN && divisor == -1)
//         return INT_MAX;
//     return (dividend / divisor);
// }

/*OPTIMAL- Without '/' Symbol*/
int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    if (dividend == divisor)
        return 1;

    bool sign = (dividend < 0) == (divisor < 0);

    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
    long long ans = 0; // Use long long to avoid overflow

    while (n >= d)
    {
        int i = 0;
        while (i < 31 && n >= (d << i)) // Ensure no overflow in shift
            i++;
        i--; // Step back to the last valid shift

        ans += (1LL << i); // Use 1LL to ensure no overflow
        n -= d * (1LL << i);
    }

    ans = sign ? ans : -ans;

    // Clamp the result to INT_MIN and INT_MAX
    if (ans > INT_MAX)
        return INT_MAX;
    if (ans < INT_MIN)
        return INT_MIN;

    return (int)ans;
}

int main()
{
    int dividend, divisor;
    cout << "Enter the dividend: ";
    cin >> dividend;
    cout << "Enter the divisor: ";
    cin >> divisor;

    int result = divide(dividend, divisor);
    cout << "The quotient is: " << result << endl;
}
     