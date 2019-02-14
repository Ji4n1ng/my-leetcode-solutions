#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) return head;
    ListNode *index = head;
    int length = 1;
    while (index->next != NULL) {
        length++;
        index = index->next;
    }
    if (length == 1) return NULL;

    int left = length - n;
    if (left == 0)
        return head->next;

    ListNode *p1 = head;
    for (int i = 1; i < left; i++) {
        p1 = p1->next;
    }
    if (p1->next->next == NULL)
        p1->next = NULL;
    else
        p1->next = p1->next->next;

    return head;
}


int main() {

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    // 1->2->3->4->5
    ListNode *a1 = removeNthFromEnd(l1, 2); // return 1->2->3->5
    while (a1 != NULL) {
        cout << a1->val << " ";
        a1 = a1->next;
    }
    cout << endl;
}