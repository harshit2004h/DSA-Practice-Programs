#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[i][j] == 0)
                v.push_back(make_pair(i, j));

    for (auto it : v)
    {
        // Row to zero
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[it.first][i] = 0;

        // Column to zero
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][it.second] = 0;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 1}};
    setZeroes(matrix);
    for (auto row : matrix)
    {
        for (auto elem : row)
            cout << elem << " ";
        cout << endl;
    }
}
