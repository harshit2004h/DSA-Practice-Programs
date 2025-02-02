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
// ListNode *reverseList(ListNode *head)
// {
//     ListNode *temp = head;
//     stack<int> s;
//     while (temp != NULL)
//     {
//         s.push(temp->val);
//         temp = temp->next;
//     }
//     temp = head;
//     while (!s.empty())
//     {
//         int top = s.top();
//         s.pop();
//         temp->val = top;
//         temp = temp->next;
//     }
//     return head;
// }

/*OPTIMAL 1- ITERATIVE*/
// ListNode *reverseList(ListNode *head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;
//     ListNode *prevNode = NULL;
//     ListNode *currNode = head;
//     ListNode *nextNode = head->next;
//     while (currNode != NULL)
//     {
//         currNode->next = prevNode;
//         prevNode = currNode;
//         currNode = nextNode;
//         if (nextNode)
//             nextNode = nextNode->next;
//     }
//     return prevNode;
// }

/*OPTIMAL 2- RECURSIVE*/
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Reversing the linked list
    head = reverseList(head);

    cout << "Reversed List: ";
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
