#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int findXOR(int l, int r)
// {
//     int ans = r;
//     for (int i = l; i < r; i++)
//         ans = ans ^ i;
//     return ans;
// }

/*OPTIMAL*/
int findXOR(int l, int r)
{
    int temp1 = (l - 1) % 4;
    int temp2 = r % 4;

    int XOR1 = 0;
    switch (temp1)
    {
    case 0:
        XOR1 = l - 1;
        break;
    case 1:
        XOR1 = 1;
        break;
    case 2:
        XOR1 = l;
        break;
    case 3:
        XOR1 = 0;
        break;
    }

    int XOR2 = 0;
    switch (temp2)
    {
    case 0:
        XOR2 = r;
        break;
    case 1:
        XOR2 = 1;
        break;
    case 2:
        XOR2 = r + 1;
        break;
    case 3:
        XOR2 = 0;
        break;
    }

    return XOR1 ^ XOR2;
}

int main()
{
    cout << "XOR of numbers from 3 to 9: " << findXOR(3, 9) << endl;
    cout << "XOR of numbers from 1 to 5: " << findXOR(1, 5) << endl;
    cout << "XOR of numbers from 10 to 12: " << findXOR(10, 12) << endl;
}
