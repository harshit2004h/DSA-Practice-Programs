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

ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

/*BETTER*/
// ListNode *reverseKGroup(ListNode *head, int k)
// {
//     ListNode dummy(-1);
//     dummy.next = head;
//     ListNode *prev = &dummy;
//     while (true)
//     {
//         ListNode *temp = prev;
//         for (int i = 0; i < k && temp != NULL; i++)
//             temp = temp->next;
//         if (temp == NULL)
//             break;
//         ListNode *start = prev->next;
//         ListNode *nextGroup = temp->next;
//         ListNode *newHead = reverseLinkedList(start, temp->next);
//         prev->next = newHead;
//         start->next = nextGroup;
//         prev = start;
//     }
//     return dummy.next;
// }

/*OPTIMAL*/
ListNode *getKthNode(ListNode *temp, int k)
{
    k -= 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevLast = NULL;
    while (temp != NULL)
    {
        ListNode *kThNode = getKthNode(temp, k);
        if (kThNode == NULL)
        {
            if (prevLast)
                prevLast->next = temp;
            break;
        }

        ListNode *nextNode = kThNode->next;
        kThNode->next = NULL;
        reverseLinkedList(temp);
        if (temp == head)
            head = kThNode;
        else
            prevLast->next = kThNode;

        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reverse in groups of size k
    int k = 3;
    head = reverseKGroup(head, k);

    // Print the reversed list
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
