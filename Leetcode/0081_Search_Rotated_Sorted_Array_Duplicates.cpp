#include <bits/stdc++.h>
using namespace std;
bool search(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return true;

        if (arr[start] == arr[mid] && arr[mid] == arr[end])
        {
            start++;
            end--;
            continue;
        }

        if (arr[start] <= arr[mid])
        {
            if (arr[start] <= target && target <= arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (arr[mid] <= target && target <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    if (search(arr, target))
        cout << "Target " << target << " found in the array" << endl;
    else
        cout << "Target " << target << " not found in the array" << endl;

    target = 3;
    if (search(arr, target))
        cout << "Target " << target << " found in the array" << endl;
    else
        cout << "Target " << target << " not found in the array" << endl;
}
