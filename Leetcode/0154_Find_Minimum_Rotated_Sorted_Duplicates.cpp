#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL*/
int findMin(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1, mid = 0;
    int ans = arr[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[end])
            start = mid + 1;
        else if (arr[mid] < arr[start])
            end = mid;
        else
            end--;
    }
    return arr[start];
}

int main()
{
    vector<int> arr = {3, 1};
    cout << "Answer is- " << findMin(arr);
}