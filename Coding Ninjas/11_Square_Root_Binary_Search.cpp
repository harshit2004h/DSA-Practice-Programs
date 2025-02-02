#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL 1*/
int floorSqrt(int n)
{
    int start = 1, end = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        long long temp = (long long)mid * mid;

        if (temp == (long long)n)
            return mid;

        if (temp > (long long)n)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start - 1;
}

/*OPTIMAL  2*/
// int floorSqrt(int n)
// {
//     int ans=sqrt(n);
//     return ans;
// }

int main()
{
    int n = 16;
    cout << "Floor square root of " << n << " is: " << floorSqrt(n) << endl;
    n = 27;
    cout << "Floor square root of " << n << " is: " << floorSqrt(n) << endl;
}
