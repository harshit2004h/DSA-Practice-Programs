#include <bits/stdc++.h>
using namespace std;
long long sumOfDivisors(int N)
{
    long long sum = 0;

    // iterating from 1 to N.
    for (int i = 1; i <= N; ++i)
        // calculating and accumulating the sum of divisors.
        sum += (N / i) * i;

    // returning the sum of divisors.
    return sum;
}

int main()
{
    cout << "Answer is- " << sumOfDivisors(5);
}