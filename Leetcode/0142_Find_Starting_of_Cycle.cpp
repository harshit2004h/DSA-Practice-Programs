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
// ListNode *detectCycle(ListNode *head)
// {
//     if (head == NULL || head->next == NULL)
//         return NULL;
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
//             return temp;
//     }
//     return NULL;
// }

/*OPTIMAL*/
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return NULL;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    // Creating a linked list with a cycle:
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Cycle: 4 -> 2

    ListNode *cycleNode = detectCycle(head);
    if (cycleNode)
        cout << "The cycle starts at node with value: " << cycleNode->val << endl;
    else
        cout << "There is no cycle in the linked list." << endl;

    // Creating a linked list without a cycle:
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = nullptr;

    cycleNode = detectCycle(head2);
    if (cycleNode)
        cout << "The cycle starts at node with value: " << cycleNode->val << endl;
    else
        cout << "There is no cycle in the linked list." << endl;
}
