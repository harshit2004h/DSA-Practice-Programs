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
// bool hasCycle(ListNode *head)
// {
//     if (head == NULL || head->next == NULL)
//         return false;
//     unordered_map<ListNode *, bool> m;
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         if (m.find(temp) == m.end())
//         {
//             m[temp] = true;
//             temp = temp->next;
//         }
//         else
//             return true;
//     }
//     return false;
// }

/*OPTIMAL*/
bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    // Creating a linked list with a cycle:
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Cycle: 4 -> 2

    if (hasCycle(head))
        cout << "The linked list has a cycle." << endl;
    else
        cout << "The linked list does not have a cycle." << endl;

    // Creating a linked list without a cycle:
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = nullptr;

    if (hasCycle(head2))
        cout << "The linked list has a cycle." << endl;
    else
        cout << "The linked list does not have a cycle." << endl;
}
