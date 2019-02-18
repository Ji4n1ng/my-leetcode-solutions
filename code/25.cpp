#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 翻转链表
ListNode* reverse(ListNode* head) {
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

// 从 k = 2 开始考虑。
// 从前往后走，当走过的节点的个数达到k时，就把这个小group交给上面的方法来翻转，把结果存到result里面。
// 每一次的小group的头节点是 g_head，最后剩下的如果不够k，把g_head添加到result里。
// 最后将result里的子链表合成一个链表。
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return head;
    if (k == 1) return head;
    int i = 0;
    ListNode *g_head = head;
    vector<ListNode*> result;
    while (head != NULL) {
        i++;
        if (i == k) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = NULL;
            tmp = reverse(g_head);
            result.push_back(tmp);
            i = 0;
            g_head = head;
        } else {
            head = head->next;
        }
    }
    if (g_head != NULL) result.push_back(g_head);
    ListNode *n_head = result[0];
    for(int i = 0; i < result.size() - 1; i++) {
        ListNode* t = result[0];
        while (t->next != NULL) {
            t = t->next;
        }
        if (i+1 < result.size()) {
            t->next = result[i+1];
        }
    }
    return n_head;
}

int main() {

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    // 1->2->3->4->5
    ListNode *a1 = reverseKGroup(l1, 2); // return 2->1->4->3->5
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
    // 1->2->3->4->5
    ListNode *a2 = reverseKGroup(l2, 3); // return 3->2->1->4->5
    while (a2 != NULL) {
        cout << a2->val << " ";
        a2 = a2->next;
    }
    cout << endl;
}