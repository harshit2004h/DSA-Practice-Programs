#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*BRUTE FORCE*/
// ListNode *sortList(ListNode *head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;
//     vector<int> v;
//     ListNode *temp = head;
//     while (temp)
//     {
//         v.push_back(temp->val);
//         temp = temp->next;
//     }
//     sort(v.begin(), v.end());
//     temp = head;
//     int i = 0;
//     while (temp)
//     {
//         temp->val = v[i++];
//         temp = temp->next;
//     }
//     return head;
// }

/*OPTIMAL- MERGE SORT*/
ListNode *Merge(ListNode *left, ListNode *right)
{
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    ListNode *ans = new ListNode(-1);
    ListNode *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->val < right->val)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if (left != NULL)
        temp->next = left;

    if (right != NULL)
        temp->next = right;

    ans = ans->next;
    return ans;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *left = head;
    ListNode *right = slow->next;
    slow->next = NULL;

    left = sortList(left);
    right = sortList(right);

    ListNode *ans = Merge(left, right);
    return ans;
}

int main()
{
    // Test Case: Create an unsorted linked list
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    // Sort the list
    head = sortList(head);

    // Print the sorted list
    cout << "Sorted list: ";
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
