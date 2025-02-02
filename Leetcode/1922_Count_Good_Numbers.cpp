#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long powerMod(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int countGoodNumbers(long long n)
{
    long long even = n / 2;
    long long odd = n - even;
    long long total = (powerMod(5, odd, MOD) * powerMod(4, even, MOD)) % MOD;
    return total;
}

int main()
{
    long long n;
    cout << "Enter the length of the sequence (n): ";
    cin >> n;

    int result = countGoodNumbers(n);
    cout << "The count of good numbers for n = " << n << " is: " << result << endl;
}
