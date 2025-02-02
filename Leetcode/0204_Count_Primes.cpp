#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// bool isPrime(int n)
// {
//     if (n <= 1)
//         return false;
//     int count = 0;
//     for (int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             if (n / i == i)
//                 count++;
//             else
//                 count += 2;
//         }
//     }
//     return count == 2;
// }
//
// int countPrimes(int n)
// {
//     int count = 0;
//     for (int i = 2; i < n; i++)
//         if (isPrime(i))
//             count++;
//     return count;
// }

/*BETTER*/
// int countPrimes(int n)
// {
//     int c = 0;
//     vector<bool> prime(n + 1, true);
//     prime[0] = prime[1] = false;
//     for (int i = 2; i < n; i++)
//     {
//         if (prime[i])
//         {
//             c++;
//             for (int j = 2 * i; j < n; j += i)
//                 prime[j] = 0;
//         }
//     }
//     return c;
// }

/*OPTIMAL*/
int countPrimes(int n)
{
    if (n <= 2)
        return 0;

    int c = 0;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n;
                 j += i)
                prime[j] = false;
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            c++;
    }

    return c;
}

int main()
{
    // 10
    cout << countPrimes(30) << endl;
}
