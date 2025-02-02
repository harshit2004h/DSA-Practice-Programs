#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     int i = 0, j = 0;
//     vector<int> ans;
//     while (i < m && j < n)
//     {
//         if (nums1[i] < nums2[j])
//             ans.push_back(nums1[i++]);
//         else
//             ans.push_back(nums2[j++]);
//     }
//     while (i < m)
//         ans.push_back(nums1[i++]);
//     while (j < n)
//         ans.push_back(nums2[j++]);
//     for (int k = 0; k < m + n; ++k)
//         nums1[k] = ans[k];
// }

/*OPTIMAL 1*/
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m - 1, right = 0;
    while (left >= 0 && right < n)
    {
        if (nums1[left] > nums2[right])
        {
            nums1[m + right] = nums2[right];
            swap(nums1[left], nums1[m + right]);
            left--;
            right++;
        }
        else
            break;
    }
    while (right < n)
    {
        nums1[m + right] = nums2[right];
        right++;
    }
    sort(nums1.begin(), nums1.end());
}

/*OPTIMAL 2*/
// void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2)
// {
//     if (arr1[ind1] > arr2[ind2])
//     {
//         swap(arr1[ind1], arr2[ind2]);
//     }
// }

// void merge(long long arr1[], long long arr2[], int n, int m)
// {
//     // len of the imaginary single array:
//     int len = n + m;

//     // Initial gap:
//     int gap = (len / 2) + (len % 2);

//     while (gap > 0)
//     {
//         // Place 2 pointers:
//         int left = 0;
//         int right = left + gap;
//         while (right < len)
//         {
//             // case 1: left in arr1[]
//             // and right in arr2[]:
//             if (left < n && right >= n)
//             {
//                 swapIfGreater(arr1, arr2, left, right - n);
//             }
//             // case 2: both pointers in arr2[]:
//             else if (left >= n)
//             {
//                 swapIfGreater(arr2, arr2, left - n, right - n);
//             }
//             // case 3: both pointers in arr1[]:
//             else
//             {
//                 swapIfGreater(arr1, arr1, left, right);
//             }
//             left++, right++;
//         }
//         // break if iteration gap=1 is completed:
//         if (gap == 1)
//             break;

//         // Otherwise, calculate new gap:
//         gap = (gap / 2) + (gap % 2);
//     }
// }

int main()
{
    vector<int> nums1 = {0, 0, 3, 0, 0, 0, 0, 0, 0};
    vector<int> nums2 = {-1, 1, 1, 1, 2, 3};
    merge(nums1, 3, nums2, 6);
    for (auto i : nums1)
        cout << i << " ";
}
