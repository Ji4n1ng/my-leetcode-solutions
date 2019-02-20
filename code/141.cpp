#include <iostream>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 所有走过的节点，都指向了 stop 节点
// 如果某个节点的 next->next->val == INT_MAX 
// 则证明有 cycle 存在
// 注意一种特殊情况就是，这个尾节点指向了自身。
bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode *stop = new ListNode(INT_MAX);
    ListNode *p1 = head->next;
    while(true) {
        if (p1 == head) return true;
        if (p1->next == NULL) {
            return false;
        }
        if (p1->next->val != INT_MAX) {
            head->next = stop;
            head = p1;
            p1 = p1->next;
        } else {
            return true;
        }
    }
    return false;
}

// 答案一
// 看了答案才知道，这个 ListNode 里面的 val 不重复。。这不就用个 hashmap 分分钟的事吗。
// 题目中没说 val 重不重复，真尴尬=

// 答案二
// 这个思路比较厉害。
// 最好的方法是时间复杂度O(n)，空间复杂度O(1)，设置两个指针，一个快，一个慢，
// 快的指针每次走两步，慢的指针每次走一布，如果快指针和慢指针相遇，则说明有环。
bool hasCycle2(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {

    ListNode *l1 = new ListNode(3);
    ListNode *n1 = new ListNode(2);
    l1->next = n1;
    l1->next->next = new ListNode(0);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = n1;

    // [3,2,0,-4], pos = 1
    bool r1 = hasCycle(l1); // return true
    cout << r1 << endl;


    ListNode *l2 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    l2->next = n2;
    n2->next = l2;

    // [1,2], pos = 0
    bool r2 = hasCycle(l2); // return true
    cout << r2 << endl;

    ListNode *l3 = new ListNode(1);
    l3->next = l3;

    // [1], pos = 0
    bool r3 = hasCycle(l3); // return true
    cout << r3 << endl;
}