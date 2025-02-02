#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// int inversionCount(vector<int> &arr)
// {
//     int n = arr.size();
//     int count = 0;
//     for (int i = 0; i < n; i++)
//         for (int j = i + 1; j < n; j++)
//             if (arr[i] > arr[j])
//                 count++;
//     return count;
// }

/*OPTIMAL*/
void merge(vector<int> &arr, int start, int end, int &count)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    vector<int> first(len1), second(len2);

    for (int i = 0; i < len1; i++)
        first[i] = arr[start + i];
    for (int i = 0; i < len2; i++)
        second[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < len1 && j < len2)
    {
        if (first[i] > second[j])
        {
            arr[k++] = second[j++];
            count += (len1 - i); // Increment count for inversions
        }
        else
        {
            arr[k++] = first[i++];
        }
    }

    // Copy remaining elements
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

int inversionCount(vector<int> arr)
{
    int count = 0;
    MergeSort(arr, 0, arr.size() - 1, count);
    return count;
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "Answer is- " << inversionCount(arr);
}