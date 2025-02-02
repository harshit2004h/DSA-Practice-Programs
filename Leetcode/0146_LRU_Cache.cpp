#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k;
        val = v;
    }
};

class LRUCache
{
public:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node *newnode)
    {
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int K)
    {
        if (m.find(K) != m.end())
        {
            Node *resnode = m[K];
            int res = resnode->val;
            m.erase(K);
            deletenode(resnode);
            addnode(resnode);
            m[K] = head->next;
            return res;
        }

        return -1;
    }

    void put(int K, int value)
    {
        if (m.find(K) != m.end())
        {
            Node *existingnode = m[K];
            m.erase(K);
            deletenode(existingnode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new Node(K, value));
        m[K] = head->next;
    }
};

int main()
{
    // First example
    LRUCache cache1(2); // Cache capacity is 2
    cache1.put(1, 1);
    cache1.put(2, 2);
    cout << cache1.get(1) << " ";  // 1
    cache1.put(3, 3);              // Evicts key 2
    cout << cache1.get(2) << " ";  // -1 (not found)
    cache1.put(4, 4);              // Evicts key 1
    cout << cache1.get(1) << " ";  // -1 (not found)
    cout << cache1.get(3) << " ";  // 3
    cout << cache1.get(4) << endl; // 4

    // Second example
    LRUCache cache2(3); // Cache capacity is 3
    cache2.put(1, 10);
    cache2.put(2, 20);
    cache2.put(3, 30);
    cout << cache2.get(1) << " ";  // 10
    cache2.put(4, 40);             // Evicts key 2
    cout << cache2.get(2) << " ";  // -1 (not found)
    cache2.put(5, 50);             // Evicts key 3
    cout << cache2.get(3) << " ";  // -1 (not found)
    cout << cache2.get(4) << " ";  // 40
    cout << cache2.get(5) << endl; // 50
}
