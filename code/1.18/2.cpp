#include <bits/stdc++.h>

using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
} ListNode;

vector<int> reversePrint(ListNode *head) {
    stack<int> stk;
    while (head != nullptr) {
        stk.push(head->val);
        head = head->next;
    }
    vector<int> res;
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

int main() {
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    vector<int> a = reversePrint(n1);
    int len = a.size();
    for (int i = 0; i < len; i++)
        printf("%d", a[i]);
}