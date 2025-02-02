#include <bits/stdc++.h>
using namespace std;
/*OPTIMAL*/
void merge(vector<int> &arr, int start, int end, int &count)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    vector<long long> first(len1), second(len2);

    for (int i = 0; i < len1; i++)
        first[i] = arr[start + i];
    for (int i = 0; i < len2; i++)
        second[i] = arr[mid + 1 + i];

    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (first[i] > 2LL * second[j])
        {
            count += (len1 - i);
            j++;
        }
        else
            i++;
    }

    i = 0, j = 0;
    int k = start;
    while (i < len1 && j < len2)
    {
        if (first[i] <= second[j])
            arr[k++] = first[i++];
        else
            arr[k++] = second[j++];
    }

    while (i < len1)
        arr[k++] = first[i++];
    while (j < len2)
        arr[k++] = second[j++];
}

void MergeSort(vector<int> &arr, int start, int end, int &count)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid, count);
    MergeSort(arr, mid + 1, end, count);
    merge(arr, start, end, count);
}

int reversePairs(vector<int> &arr)
{
    int count = 0;
    MergeSort(arr, 0, arr.size() - 1, count);
    return count;
}

int main()
{
    vector<int> arr1 = {1, 3, 2, 3, 1};
    cout << reversePairs(arr1) << endl; // 2

    vector<int> arr2 = {2, 4, 3, 5, 1};
    cout << reversePairs(arr2) << endl; // 3
}
