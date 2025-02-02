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
// ListNode *removeNthFromEnd(ListNode *head, int n)
// {
//     if (head == NULL || head->next == NULL)
//         return NULL;
//     ListNode *temp = head;
//     int total = 0;
//     while (temp != NULL)
//     {
//         total++;
//         temp = temp->next;
//     }
//     int back = total - n;
//     if (back == 0)
//         return head->next;
//     temp = head;
//     for (int i = 0; i < back - 1; i++)
//         temp = temp->next;
//     if (temp->next)
//         temp->next = temp->next->next;
//     return head;
// }

/*OPTIMAL*/
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *fast = head;
    ListNode *slow = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (fast == NULL)
        return head->next;

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    if (slow->next)
        slow->next = slow->next->next;
    return head;
}

int main()
{
    // Test Case: Remove the 2nd node from the end
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove 2nd node from the end

    head = removeNthFromEnd(head, n);

    // Print the updated list
    cout << "Updated list: ";
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
