#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return head;
    ListNode *index = head;
    int n = 0;
    while (index != NULL) {
        n++;
        index = index->next;
    }
    k = k % n;
    if (k == 0) return head;

    int l = n - k;
    ListNode *rightHead, *rightIndex, *index2 = head;
    for (int i = 1; i < l; i++) {
        index2 = index2->next;
    }
    rightHead = index2->next;
    index2->next = NULL;
    rightIndex = rightHead;
    while (rightIndex->next != NULL) {
        rightIndex = rightIndex->next;
    }
    rightIndex->next = head;

    return rightHead;
}

int main() {

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    // 1->2->3->4->5
    ListNode *a1 = rotateRight(l1, 2); // return 4->5->1->2->3
    while (a1 != NULL) {
        cout << a1->val << " ";
        a1 = a1->next;
    }
    cout << endl;

    ListNode *l2 = new ListNode(0);
    l2->next = new ListNode(1);
    l2->next->next = new ListNode(2);
    // 0->1->2
    ListNode *a2 = rotateRight(l2, 4); // return 2->0->1
    while (a2 != NULL) {
        cout << a2->val << " ";
        a2 = a2->next;
    }
    cout << endl;
}
