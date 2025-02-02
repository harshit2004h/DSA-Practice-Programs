#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE- GIVES TIME LIMIT EXCEEDED*/
/*Time Complexity- O(n*K)*/
// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     vector<int> ans;
//     for (int i = 0; i <= n - k; i++)
//     {
//         priority_queue<int> pq;
//         for (int j = i; j < i + k; j++)
//             pq.push(nums[j]);
//         ans.push_back(pq.top());
//     }
//     return ans;
// }

/*BETTER*/
/*Time Complexity- O(nlogK)*/
// vector<int> maxSlidingWindow(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     priority_queue<pair<int, int>> pq;
//     vector<int> ans;
//     for (int i = 0; i < k; i++)
//         pq.push({arr[i], i});
//     ans.push_back(pq.top().first);
//     for (int i = k; i < n; i++)
//     {
//         pq.push({arr[i], i});
//         while (pq.top().second <= (i - k))
//             pq.pop();
//         ans.push_back(pq.top().first);
//     }
//     return ans;
// }

/*OPTIMAL*/
/*Time Complexity- O(2n)*/
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
    int n = arr.size();
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = maxSlidingWindow(nums1, k1);
    for (int x : result1)
        cout << x << " "; // 3 3 5 5 6 7
    cout << endl;

    vector<int> nums2 = {1, 3, 1, 2, 0, 5};
    int k2 = 3;
    vector<int> result2 = maxSlidingWindow(nums2, k2);
    for (int x : result2)
        cout << x << " "; // 3 3 2 5
    cout << endl;

    vector<int> nums3 = {1};
    int k3 = 1;
    vector<int> result3 = maxSlidingWindow(nums3, k3);
    for (int x : result3)
        cout << x << " "; // 1
    cout << endl;
}
