#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// bool isThree(int n)
// {
//     int count = 0;
//     for (int i = 1; i <= n; i++)
//         if (n % i == 0)
//             count++;
//     if (count == 3)
//         return true;
//     return false;
// }

/*OPTIMAL*/
bool isThree(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
                count += 2;
            else
                count++;
        }
    }
    if (count == 3)
        return true;
    return false;
}

int main()
{
    // true
    cout << boolalpha << isThree(9) << endl;

    // false
    cout << boolalpha << isThree(10) << endl;

    // false
    cout << boolalpha << isThree(16) << endl;
}
