#include <bits/stdc++.h>

using namespace std;

class CQueue
{
public:
    stack<int> a,b;
    CQueue(){}
    void appendTail(int val)
    {
        a.push(val);
    }
    int deleteHead()
    {
        if(!b.empty())
        {
           int tmp=b.top();
           b.pop();
            return tmp;
        }
        if(a.empty())
            return -1;
        while (!a.empty())
        {
            int tmp=a.top();
            a.pop();
            b.push(tmp);
        }
        int tmp=b.top();
        b.pop();
        return tmp;
    }

};
