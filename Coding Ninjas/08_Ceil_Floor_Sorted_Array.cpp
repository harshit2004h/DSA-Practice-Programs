#include <bits/stdc++.h>
using namespace std;
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{
    int start=0, end=n-1, mid=0;
    int floor=-1, ceil=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]>x)
        {
            ceil=arr[mid];
            end=mid-1;
        }
        else if(arr[mid]<x)
        {
            floor=arr[mid];
            start=mid+1;
        }
        else
        {
            floor=ceil=arr[mid];
            break;
        }
    }
    return {floor, ceil};
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int n = arr.size();
    int x = 5;

    pair<int, int> result = getFloorAndCeil(arr, n, x);

    cout << "Floor of " << x << " is: " << result.first << endl;
    cout << "Ceil of " << x << " is: " << result.second << endl;
}