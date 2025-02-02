#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// class StockSpanner
// {
//     vector<int> v;
// public:
//     StockSpanner() : v() {}
//     int next(int price)
//     {
//         v.push_back(price);
//         int count = 0;
//         for (int i = v.size() - 1; i >= 0; i--)
//         {
//             if (v[i] <= price)
//                 count++;
//             else
//                 break;
//         }
//         return count;
//     }
// };

/*OPTIMAL*/
class StockSpanner
{
    stack<pair<int, int>> s;

public:
    StockSpanner() : s() {}

    int next(int price)
    {
        int temp = 1;
        while (!s.empty() && s.top().first <= price)
        {
            temp += s.top().second;
            s.pop();
        }
        s.push({price, temp});
        return temp;
    }
};

int main()
{
    StockSpanner spanner;

    // First example
    cout << spanner.next(100) << " "; // 1
    cout << spanner.next(80) << " ";  // 1
    cout << spanner.next(60) << " ";  // 1
    cout << spanner.next(70) << " ";  // 2
    cout << spanner.next(60) << " ";  // 1
    cout << spanner.next(75) << " ";  // 4
    cout << spanner.next(85) << endl; // 6

    // Second example
    StockSpanner spanner2;
    cout << spanner2.next(28) << " ";  // 1
    cout << spanner2.next(14) << " ";  // 1
    cout << spanner2.next(28) << " ";  // 3
    cout << spanner2.next(35) << " ";  // 4
    cout << spanner2.next(46) << " ";  // 5
    cout << spanner2.next(53) << " ";  // 6
    cout << spanner2.next(66) << " ";  // 7
    cout << spanner2.next(80) << " ";  // 8
    cout << spanner2.next(87) << " ";  // 9
    cout << spanner2.next(88) << endl; // 10
}
