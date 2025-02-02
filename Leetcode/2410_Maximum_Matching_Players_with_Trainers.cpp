#include <bits/stdc++.h>
using namespace std;
int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
{
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int i = 0, j = 0;
    while (j < trainers.size() && i < players.size())
    {
        if (players[i] <= trainers[j])
            i++;
        j++;
    }
    return i;
}

int main()
{
    // Example 1
    vector<int> players1 = {4, 7, 9};
    vector<int> trainers1 = {8, 5, 6};
    cout << matchPlayersAndTrainers(players1, trainers1) << endl; // 2

    // Example 2
    vector<int> players2 = {1, 1, 1};
    vector<int> trainers2 = {10, 9, 8};
    cout << matchPlayersAndTrainers(players2, trainers2) << endl; // 3

    // Example 3
    vector<int> players3 = {6, 5, 4};
    vector<int> trainers3 = {3, 2, 1};
    cout << matchPlayersAndTrainers(players3, trainers3) << endl; // 0
}
