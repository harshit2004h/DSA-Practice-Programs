#include <bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &nums1, vector<int> &nums2, int n1, int n2, int k)
{
    if (n1 > n2)
        return kthElement(nums2, nums1, n2, n1, k);
    int start = max(0, k - n2), end = min(k, n1);

    while (start <= end)
    {
        int mid1 = start + (end - start) / 2;
        int mid2 = k - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            end = mid1 - 1;
        else
            start = mid1 + 1;
    }
    return 0;
}

int main()
{
    vector<int> nums1 = {2, 3, 5, 7, 11};
    vector<int> nums2 = {1, 4, 6, 8, 9, 10};

    int k = 5;
    int n1 = nums1.size(), n2 = nums2.size();
    int result = kthElement(nums1, nums2, n1, n2, k);

    cout << "The " << k << "th element is: " << result << endl;
    return 0;
}
