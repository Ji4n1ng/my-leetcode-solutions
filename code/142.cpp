#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 我是用存储 val 和 指针 的方式来做的，效率比较低，只有 5.34。
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;
    unordered_map<int, vector<ListNode*>> map;
    int index = 0;
    while(head != NULL) {
        int val = head->val;
        if (map.find(val) == map.end()) {
            vector<ListNode*> v;
            v.push_back(head);
            map[val] = v;
        } else {
            auto v = map[val];
            for (auto i: v) {
                if (head == i)
                    return head;
            }
            v.push_back(head);
            map[val] = v;
        }
        head = head->next;
    }
    return NULL;
}

// 推荐答案，还是利用了和 141 大致的思路。
// 建议阅读 pdf 里的解析。
ListNode *detectCycle2(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode *slow2 = head;

            while (slow2 != slow) {
                slow2 = slow2->next;
                slow = slow->next;
            }
            return slow2;
        }
    }
    return nullptr;
}


int main() {

//    ListNode *l1 = new ListNode(3);
//    ListNode *n1 = new ListNode(2);
//    l1->next = n1;
//    l1->next->next = new ListNode(0);
//    l1->next->next->next = new ListNode(4);
//    l1->next->next->next->next = n1;
//
//    // [3,2,0,-4], pos = 1
//    ListNode *r1 = detectCycle(l1); // return 2
//    cout << r1->val << endl;
//
//
//    ListNode *l2 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    l2->next = n2;
//    n2->next = l2;
//
//    // [1,2], pos = 0
//    ListNode *r2 = detectCycle(l2); // return 1
//    cout << r2->val << endl;
//
//    ListNode *l3 = new ListNode(1);
//    l3->next = l3;
//
//    // [1], pos = 0
//    ListNode *r3 = detectCycle(l3); // return 1
//    cout << r3->val << endl;



    ListNode *l4 = new ListNode(-1);
    l4->next = new ListNode(-7);
    l4->next->next = new ListNode(7);
    l4->next->next->next = new ListNode(-4);
    l4->next->next->next->next = new ListNode(19);
    l4->next->next->next->next->next = new ListNode(6);
    l4->next->next->next->next->next->next = new ListNode(-9);
    l4->next->next->next->next->next->next->next = new ListNode(-5);
    l4->next->next->next->next->next->next->next->next = new ListNode(-2);
    ListNode *n4 = new ListNode(-5);
    l4->next->next->next->next->next->next->next->next->next = n4;
    n4->next = n4;
    // [-1,-7,7,-4,19,6,-9,-5,-2,-5] pos: 9
    ListNode *r4 = detectCycle2(l4); // return -5
    cout << r4->val << endl;
}