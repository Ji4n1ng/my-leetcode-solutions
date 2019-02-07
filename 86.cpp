#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    if (head == NULL) return head;
    ListNode *less = new ListNode(-1), *more = new ListNode(-1);
    ListNode *lessHead = less, *moreHead = more;

    while (head != NULL) {
        if (head->val < x) {
            less->next = head;
            less = less->next;
        } else {
            more->next = head;
            more = more->next;
        }
        head = head->next;
    }
    if (less->next != NULL)
        less->next = NULL;
    if (more->next != NULL)
        more->next = NULL;
    if (moreHead->next != NULL && lessHead->next != NULL) {
        less->next = moreHead->next;
    }
    if (lessHead->next == NULL) {
        return moreHead->next;
    }
    return lessHead->next;
}



int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(2);
    l1->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next = new ListNode(2);

    ListNode *a1 = partition(l1, 3); // return 1->2->2->4->3->5
    while (a1 != NULL) {
        cout << a1->val << " ";
        a1 = a1->next;
    }
    cout << endl;
}

