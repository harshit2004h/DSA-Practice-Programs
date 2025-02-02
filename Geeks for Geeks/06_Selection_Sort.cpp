#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}

int main()
{
    int arr[] = {5, 1, 2, 7, 9, 1, 3, 5, 74, 8, 0};
    selectionSort(arr, 11);
    cout << "The sorted array is- ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " , ";
}