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
// bool isPalindrome(ListNode *head)
// {
//     vector<int> arr;
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         arr.push_back(temp->val);
//         temp = temp->next;
//     }
//     int n = arr.size();
//     for (int i = 0, j = n - 1; i <= j; i++, j--)
//         if (arr[i] != arr[j])
//             return false;
//     return true;
// }

/*OPTIMAL*/
ListNode *reverseLinkedList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = reverseLinkedList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *newHead = reverseLinkedList(slow->next);
    ListNode *first = head;
    ListNode *second = newHead;
    while (second != NULL)
    {
        if (first->val != second->val)
        {
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLinkedList(newHead);
    return true;
}

int main()
{
    // Test Case 1: Palindromic linked list
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);

    if (isPalindrome(head1))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    // Test Case 2: Non-palindromic linked list
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);

    if (isPalindrome(head2))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    // Test Case 3: Single-node linked list
    ListNode *head3 = new ListNode(1);

    if (isPalindrome(head3))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;
}