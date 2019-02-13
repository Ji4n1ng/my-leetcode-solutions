#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates2(ListNode* head) {
    if (head == NULL) return head;
    ListNode *index = head, *h = new ListNode(-1);
    ListNode *h1 = h;
    int duplicate = -1;
    while(index != NULL) {
        while (index != NULL && index->next != NULL && index->val == index->next->val) {
            duplicate = index->val;
            while (index != NULL && duplicate == index->val) {
                index = index->next;
            }
        }
        if (index != NULL) {
            h->next = index;
            h = h->next;
            index = index->next;
        }
    }
    h->next = NULL;
    return h1->next;
}


ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return head;
    ListNode*h = new ListNode(-1);

}

int main() {

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(3);
    l1->next->next->next->next = new ListNode(4);
    l1->next->next->next->next->next = new ListNode(4);
    l1->next->next->next->next->next->next = new ListNode(5);
    // 1->2->3->3->4->4->5
    ListNode *a1 = deleteDuplicates(l1); // return 1->2->5
    while (a1 != NULL) {
        cout << a1->val << " ";
        a1 = a1->next;
    }
    cout << endl;
}
