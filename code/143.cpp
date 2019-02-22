#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 翻转链表
ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *p = head, *p1 = head->next, *p2;
    bool first = true;
    while (true) {
        p2 = p1->next;
        p1->next = p;
        if (first) {
            p->next = NULL;
            first = false;
        }
        p = p1;
        if (p2 != NULL)
            p1 = p2;
        else
            break;
    }
    return p;
}

void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL) return;

    // 遍历，求出链表长度，以及是否是奇数
    int length = 1;
    ListNode *tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    int count = length / 2;
    int n = length % 2;
    // 从中间拆分为两个链表
    tail = head;
    for (int i = 0; i < count - 1; i++) {
        tail = tail->next; 
    }
    if (n == 1) {
        tail = tail->next;
    } 
    ListNode *tmp = tail;
    tail = tail->next;
    tmp->next = NULL;
    // 翻转后面的子链表
    tail = reverse(tail);
    // 合并两个链表
    ListNode *p = head, *p1 = head->next, *t1 = tail->next;
    for (int i = 0; i < count; i++) {
        p->next = tail;
        tail->next = p1;
        if (p1 == NULL || t1 == NULL) break;
        p = p1;
        tail = t1;
        p1 = p1->next;
        t1 = t1->next;
    }
}



int main() {

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    // 1->2->3->4->5
    reorderList(l1); // return 1->5->2->4->3
    while (l1 != NULL) {
        cout << l1->val << " ";
        l1 = l1->next;
    }
    cout << endl;


    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(3);
    l2->next->next->next = new ListNode(4);
    // 1->2->3->4
    reorderList(l2); // return 1->4->2->3
    while (l2 != NULL) {
        cout << l2->val << " ";
        l2 = l2->next;
    }
    cout << endl;

    
}