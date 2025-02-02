#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL-1*/
// bool lemonadeChange(vector<int> &bills)
// {
//     if (bills[0] == 10 || bills[0] == 20)
//         return false;
//     int five = 0, ten = 0, twenty = 0;
//     for (int i = 0; i < bills.size() && five >= 0 && ten >= 0 && twenty >= 0; i++)
//     {
//         if (bills[i] == 10)
//         {
//             ten++;
//             five--;
//         }
//         else if (bills[i] == 20)
//         {
//             twenty++;
//             five--;
//             if (ten != 0)
//                 ten--;
//             else
//                 five -= 2;
//         }
//         else
//             five++;
//     }
//     if (five < 0 || ten < 0 || twenty < 0)
//         return false;
//     return true;
//}

/*OPTIMAL-2*/
bool lemonadeChange(vector<int> &bills)
{
    if (bills[0] == 10 || bills[0] == 20)
        return false;

    int five = 0, ten = 0;
    for (int i = 0; i < bills.size() && five >= 0 && ten >= 0; i++)
    {
        if (bills[i] == 10)
        {
            ten++;
            five--;
        }
        else if (bills[i] == 20)
        {
            five--;
            if (ten != 0)
                ten--;
            else
                five -= 2;
        }
        else
            five++;
    }

    if (five < 0 || ten < 0)
        return false;
    return true;
}

int main()
{
    // Example 1
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << lemonadeChange(bills1) << endl; // true

    // Example 2
    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << lemonadeChange(bills2) << endl; // false

    // Example 3
    vector<int> bills3 = {5, 5, 5, 5, 10, 20, 10, 20};
    cout << lemonadeChange(bills3) << endl; // true

    // Example 4
    vector<int> bills4 = {10, 5, 20};
    cout << lemonadeChange(bills4) << endl; // false
}
