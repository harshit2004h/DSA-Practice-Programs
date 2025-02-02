#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int value;
    int cnt;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k;
        value = v;
        cnt = 1;
    }
};

class List
{
public:
    int size;
    Node *head;
    Node *tail;

    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *newnode)
    {
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        size++;
    }

    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
            minFreq++;

        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
            nextHigherFreqList = freqListMap[node->cnt + 1];
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
            return;

        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curSize == maxSizeCache)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
                listFreq = freqListMap[minFreq];
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

int main()
{
    // First example
    LFUCache lfu1(2);
    lfu1.put(1, 1);
    lfu1.put(2, 2);
    cout << lfu1.get(1) << endl; // 1
    lfu1.put(3, 3);
    cout << lfu1.get(2) << endl; // -1
    cout << lfu1.get(3) << endl; // 3
    lfu1.put(4, 4);
    cout << lfu1.get(1) << endl; // -1
    cout << lfu1.get(3) << endl; // 3
    cout << lfu1.get(4) << endl; // 4

    // Second example
    LFUCache lfu2(3);
    lfu2.put(1, 10);
    lfu2.put(2, 20);
    lfu2.put(3, 30);
    cout << lfu2.get(1) << endl; // 10
    lfu2.put(4, 40);
    cout << lfu2.get(2) << endl; // -1
    cout << lfu2.get(3) << endl; // 30
    cout << lfu2.get(4) << endl; // 40
}
