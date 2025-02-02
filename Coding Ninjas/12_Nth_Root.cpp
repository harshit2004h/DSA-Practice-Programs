#include <bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m)
{
    int start = 1, end = m;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Calculate mid^n with overflow check
        long long power = 1;
        for (int i = 1; i <= n; i++)
        {
            power *= mid;
            if (power > m)
            { // Early exit if power exceeds m
                power = m + 1;
                break;
            }
        }

        if (power == m)
            return mid;

        if (power > m)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    cout << n << "th root of " << m << " is: " << NthRoot(n, m) << endl;

    n = 4, m = 16;
    cout << n << "th root of " << m << " is: " << NthRoot(n, m) << endl;
}
