#include <bits/stdc++.h>
using namespace std;
int HCM(long long a, long long b)
{
    if (b == 0)
        return a;
    return HCM(b, a % b);
}

int LCM(long long a, long long b, long long c = 1)
{
    if (c % a == 0 and c % b == 0)
        return c;
    return LCM(a, b, c + 1);
}

vector<long long> lcmAndGcd(long long A, long long B)
{
    long long hcm = HCM(A, B);
    long long lcm = LCM(A, B);
    return {lcm, hcm};
}

int main()
{
    vector<long long> ans = lcmAndGcd(5, 10);

    for (auto i : ans)
        cout << i << " ";
}