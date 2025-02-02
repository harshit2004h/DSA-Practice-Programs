#include <bits/stdc++.h>
using namespace std;
int smallestDivisor(vector<int> &arr, int threshold)
{
    int n = arr.size();
    int maxEle = INT_MIN;
    for (int i = 0; i < n; i++)
        maxEle = max(maxEle, arr[i]);

    int start = 1, end = maxEle;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int temp = 0;
        for (int i = 0; i < n; i++)
            temp += ceil((double)arr[i] / (double)mid);

        if (temp <= threshold)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

int main()
{
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    cout << "Smallest divisor with threshold " << threshold << " is: " << smallestDivisor(arr, threshold) << endl;

    arr = {44, 22, 33, 11, 1};
    threshold = 10;
    cout << "Smallest divisor with threshold " << threshold << " is: " << smallestDivisor(arr, threshold) << endl;
}
