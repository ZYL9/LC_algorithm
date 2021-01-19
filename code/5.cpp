#include <bits/stdc++.h>

using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
} ListNode;

ListNode* reverseList(ListNode* head) {
    ListNode* tmp= nullptr;
    ListNode* c=head;
    ListNode* p= nullptr;
    while (c!= nullptr)
    {
        tmp=c->next;
        c->next=p;
        p=c;
        c=tmp;
    }
    return p;
}

