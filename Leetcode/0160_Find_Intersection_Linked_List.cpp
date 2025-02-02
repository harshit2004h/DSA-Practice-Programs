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
// ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
// {
//     while (head2 != NULL)
//     {
//         ListNode *temp = head1;
//         while (temp != NULL)
//         {
//             if (temp == head2)
//                 return head2;
//             temp = temp->next;
//         }
//         head2 = head2->next;
//     }
//     return NULL;
// }

/*BETTER- HASHING*/
// ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
// {
//     unordered_map<ListNode *, bool> m;
//     ListNode *temp = head1;
//     while (temp != NULL)
//     {
//         m[temp] = true;
//         temp = temp->next;
//     }
//     temp = head2;
//     while (temp != NULL)
//     {
//         if (m.find(temp) != m.end())
//             return temp;
//         temp = temp->next;
//     }
//     return NULL;
// }

/*OPTIMAL- DIFFERENCE IN LENGTH*/
// int getLength(ListNode *head)
// {
//     int len = 0;
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }
// ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
// {
//     int len1 = getLength(head1);
//     int len2 = getLength(head2);
//     int diff = abs(len1 - len2);
//     if (len1 > len2)
//     {
//         for (int i = 0; i < diff; i++)
//             head1 = head1->next;
//     }
//     else if (len2 > len1)
//     {
//         for (int i = 0; i < diff; i++)
//             head2 = head2->next;
//     }
//     while (head1 != NULL)
//     {
//         if (head1 == head2)
//             return head1;
//         head1 = head1->next;
//         head2 = head2->next;
//     }
//     return NULL;
// }

/*OPTIMAL*/
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;

    while (temp1 != temp2)
    {
        if (temp1 == NULL && temp2 == NULL)
            return NULL;
        temp1 = temp1 == NULL ? head2 : temp1->next;
        temp2 = temp2 == NULL ? head1 : temp2->next;
    }
    return temp1;
}

int main()
{
    // Create two linked lists with intersection
    ListNode *common = new ListNode(8, new ListNode(10));

    ListNode *head1 = new ListNode(4, new ListNode(1, common));
    ListNode *head2 = new ListNode(5, new ListNode(6, new ListNode(1, common)));

    // Find the intersection node
    ListNode *intersection = getIntersectionNode(head1, head2);

    // Print the result
    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found." << endl;
}
