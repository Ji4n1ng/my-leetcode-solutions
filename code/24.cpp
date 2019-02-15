#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == NULL) return head;
    ListNode *p0 = head, *p1 = head, *p2;
    bool first = true;
    while(true) {
        p2 = p1->next;
        if (p2 == NULL) break;
        p1->next = p2->next;
        p2->next = p1;
        if (first) {
            head = p2;
            first = false;
        } else {
            p0->next = p2;
        }
        p0 = p1;
        if (p1->next == NULL) break;
        p1 = p1->next;
    }
    return head;
}

int main() {

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    // 1->2->3->4
    ListNode *a1 = swapPairs(l1); // return 2->1->4->3
    while (a1 != NULL) {
        cout << a1->val << " ";
        a1 = a1->next;
    }
    cout << endl;
}