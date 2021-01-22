#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int val;
    struct Node *next;
    struct Node *random;

    Node(int x) : val(x), next(NULL), random(NULL) {
    }
} ListNode;


Node *copyRandomList(Node *head) {
    if (head == nullptr)
        return nullptr;
    Node *c = head;
    while (c != nullptr) {
        Node *tmp = new Node(c->val);
        tmp->next = c->next;
        c->next = tmp;
        c = tmp->next;
    }
    c = head;
    while (c != nullptr) {
        if(c->random!= nullptr)
            c->next->random=c->random->next;
        c=c->next->next;
    }
    c=head->next;
    Node* p=head;
    Node* r=head->next;
    while (c->next!= nullptr)
    {
        p->next=p->next->next;
        c->next=c->next->next;
        p=p->next;
        c=c->next;
    }
    p->next= nullptr;
    return r;
}