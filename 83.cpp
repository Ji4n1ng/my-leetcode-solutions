#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return head;
    ListNode *h = head, *index = head->next;
    while(index != NULL) {
        if (h->val != index->val) {
            h->next = index;
            h = index;
        }
        index = index->next;
    }
    h->next = NULL;
    return head;

}
