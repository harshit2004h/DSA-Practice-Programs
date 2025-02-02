#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/*BRUTE FORCE*/
// int lengthOfLoop(Node *head)
// {
//     unordered_map<Node *, int> visitedNodes;
//     Node *temp = head;
//     int timer = 0;
//     while (temp != NULL)
//     {
//         if (visitedNodes.find(temp) != visitedNodes.end())
//         {
//             int loopLength = timer - visitedNodes[temp];
//             return loopLength;
//         }
//         visitedNodes[temp] = timer;
//         temp = temp->next;
//         timer++;
//     }
//     return 0;
// }

/*OPTIMAL*/
int lengthOfLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return 0;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return 0;

    int count = 0;
    do
    {
        fast = fast->next;
        count++;
    } while (slow != fast);

    return count;
}

int main()
{
    // Creating a linked list with a loop:
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Loop: 4 -> 2

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0)
        cout << "Length of the loop is: " << loopLength << endl;
    else
        cout << "There is no loop in the linked list." << endl;

    // Creating a linked list without a loop:
    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = nullptr;

    loopLength = lengthOfLoop(head2);
    if (loopLength > 0)
        cout << "Length of the loop is: " << loopLength << endl;
    else
        cout << "There is no loop in the linked list." << endl;
}
