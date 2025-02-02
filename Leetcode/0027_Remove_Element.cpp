#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int> &arr, int val)
{
    int n = arr.size();
    int j = n - 1, count = 0;
    for (int i = 0; i <= j;)
    {
        if (arr[i] == val)
        {
            swap(arr[i], arr[j]);
            j--;
            count++;
        }
        else
            i++;
    }
    return n - count;
}

int main()
{
    vector<int> arr = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int newSize = removeElement(arr, val);

    cout << "New size of array after removing " << val << ": " << newSize << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}
