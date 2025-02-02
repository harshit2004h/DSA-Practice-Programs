#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int celebrity(vector<vector<int>> &arr)
//  {
//      int n = arr.size();
//      vector<int> KnowsMe(n, 0);
//      vector<int> IKnows(n, 0);
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = 0; j < n; j++)
//          {
//              if (arr[i][j] == 1)
//              {
//                  IKnows[i]++;
//                  KnowsMe[j]++;
//              }
//          }
//      }
//      for (int i = 0; i < n; i++)
//          if (IKnows[i] == 0 && KnowsMe[i] == n - 1)
//              return i;
//      return -1;
//  }

/*OPTIMAL*/
int celebrity(vector<vector<int>> &arr)
{
    int n = arr.size();
    int top = 0;
    int bottom = n - 1;
    while (top < bottom)
    {
        if (arr[top][bottom] == 1)
            top++;
        else if (arr[bottom][top] == 1)
            bottom--;
        else
        {
            top++;
            bottom--;
        }
    }

    if (top > bottom)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;
        if (arr[top][i] == 0 && arr[i][top] == 1)
            continue;
        else
            return -1;
    }

    return top;
}

int main()
{
    // First example
    vector<vector<int>> party1 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};
    cout << celebrity(party1) << endl; // 1

    // Second example
    vector<vector<int>> party2 = {
        {0, 1, 1},
        {1, 0, 1},
        {0, 0, 0}};
    cout << celebrity(party2) << endl; // 2
}
