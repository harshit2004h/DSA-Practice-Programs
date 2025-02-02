#include <bits/stdc++.h>
using namespace std;
/*BRUTE FORCE*/
// class MinStack
// {
// public:
//     stack<pair<int, int>> s;
//     void push(int val)
//     {
//         if (s.empty())
//             s.push({val, val});
//         else
//             s.push({val, min(s.top().second, val)});
//     }
//     void pop()
//     {
//         s.pop();
//     }
//     int top()
//     {
//         return s.top().first;
//     }
//     int getMin()
//     {
//         return s.top().second;
//     }
// };

/*OPTIMAL*/
class MinStack
{
    stack<long long> st;
    long long mini;

public:
    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int value)
    {
        long long val = (long long)value;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long el = st.top();
        st.pop();

        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return (int)mini;
        return (int)el;
    }

    int getMin()
    {
        return (int)mini;
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; /*-3*/
    minStack.pop();
    cout << minStack.top() << endl;    /*0*/
    cout << minStack.getMin() << endl; /*-2*/
}
