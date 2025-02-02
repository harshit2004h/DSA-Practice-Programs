#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {
//     int n1 = nums1.size(), n2 = nums2.size();
//     vector<int> arr3;
//     int i = 0, j = 0;
//     while (i < n1 && j < n2)
//     {
//         if (nums1[i] < nums2[j])
//             arr3.push_back(nums1[i++]);
//         else
//             arr3.push_back(nums2[j++]);
//     }
//     while (i < n1)
//         arr3.push_back(nums1[i++]);
//     while (j < n2)
//         arr3.push_back(nums2[j++]);
//     int n = n1 + n2;
//     if (n % 2 == 1)
//         return (double)arr3[n / 2];
//     double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
//     return median;
// }

/*BETTER*/
// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {
//     int n1 = nums1.size(), n2 = nums2.size();
//     int totalSize = n1 + n2;
//     int index2 = totalSize / 2;
//     int index1 = index2 - 1;
//     int cnt = 0;
//     int index1Ele = -1, index2Ele = -1;
//     int i = 0, j = 0;
//     while (i < n1 && j < n2)
//     {
//         if (nums1[i] < nums2[j])
//         {
//             if (cnt == index1)
//                 index1Ele = nums1[i];
//             if (cnt == index2)
//                 index2Ele = nums1[i];
//             cnt++;
//             i++;
//         }
//         else
//         {
//             if (cnt == index1)
//                 index1Ele = nums2[j];
//             if (cnt == index2)
//                 index2Ele = nums2[j];
//             cnt++;
//             j++;
//         }
//     }
//     while (i < n1)
//     {
//         if (cnt == index1)
//             index1Ele = nums1[i];
//         if (cnt == index2)
//             index2Ele = nums1[i];
//         cnt++;
//         i++;
//     }
//     while (j < n2)
//     {
//         if (cnt == index1)
//             index1Ele = nums2[j];
//         if (cnt == index2)
//             index2Ele = nums2[j];
//         cnt++;
//         j++;
//     }
//     if (totalSize % 2 == 1)
//         return (double)index2Ele;
//     return (double)((double)(index1Ele + index2Ele)) / 2.0;
// }

/*OPTIMAL*/
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);
    int left = (n1 + n2 + 1) / 2;
    int start = 0, end = n1;

    while (start <= end)
    {
        int mid1 = start + (end - start) / 2;
        int mid2 = left - mid1;
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
        {
            if ((n1 + n2) % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
            end = mid1 - 1;
        else
            start = mid1 + 1;
    }
    return 0;
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8, 10};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median of the two sorted arrays is: " << median << endl;
}
