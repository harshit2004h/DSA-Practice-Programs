#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1 || arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];

        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
                start = mid + 2;
            else
                end = mid - 2;
        }
        else
        {
            if (arr[mid] == arr[mid + 1])
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    cout << "Single non-duplicate element is: " << singleNonDuplicate(arr) << endl;

    arr = {1, 1, 2, 3, 3, 4, 4};
    cout << "Single non-duplicate element is: " << singleNonDuplicate(arr) << endl;
}
