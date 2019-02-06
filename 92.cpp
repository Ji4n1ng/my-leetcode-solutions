#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n) return head;
    ListNode *index = head;
    ListNode *beforeReverse = NULL;
    for (int i = 1; i < m; i++) {
        beforeReverse = index;
        index = index->next;
    }
    ListNode *first = index, *last = index, *tmp;
    index = index->next;
    last->next = NULL;
    for (int i = m; i < n; i++) {
        tmp = index;
        index = index->next;
        tmp->next = first;
        first = tmp;
    }
    if (beforeReverse != NULL)
        beforeReverse->next = first;
    else
        head = first;

    if (index != NULL)
        last->next = index;

    return head;
}

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);

    ListNode *a1 = reverseBetween(l1, 2, 4); // return 1 4 3 2 5
    while (a1 != NULL) {
        cout << a1->val << " ";
        a1 = a1->next;
    }
    cout << endl;


    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(3);
    l2->next->next->next = new ListNode(4);
    l2->next->next->next->next = new ListNode(5);

    ListNode *a2 = reverseBetween(l2, 1, 5); // return 5 4 3 2 1
    while (a2 != NULL) {
        cout << a2->val << " ";
        a2 = a2->next;
    }
    cout << endl;
}