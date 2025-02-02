#include <bits/stdc++.h>
using namespace std;
long long getInversions(long long *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                count++;

    return count;
}

int main()
{
    long long arr[] = {52244275, 123047899, 493394237, 922363607, 378906890, 188674257, 222477309, 902683641, 860884025, 339100162};
    cout << "Answer is- " << getInversions(arr, 10);
}