#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), id(-1), next(NULL), random(NULL) {}
};

// 这道题很厉害，我一点思路也没有，实在没想出来怎么区分node。
// 这个答案和 LeetCode Hint 中的思路一样。我当时看了 Hint 也没理解怎么做。
// 答案扫描了两边，第一遍创建节点
// Old List: A --> B --> C --> D
// InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'
// 这样的话，A'跟在A后面，就一一对应了，Random就不怕找错了。
// 第二遍，就是指random
// 最后拆分为两个链表。
RandomListNode *copyRandomList(RandomListNode *head) {
    for (RandomListNode* cur = head; cur != nullptr; ) {
        RandomListNode* node = new RandomListNode(cur->label);
        node->next = cur->next;
        cur->next = node;
        cur = node->next;
    }

    for (RandomListNode* cur = head; cur != nullptr; ) {
        if (cur->random != NULL)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }

    // 拆分为两个链表
    RandomListNode dummy(-1);
    for (RandomListNode* cur = head, *new_cur = &dummy;  cur != nullptr; ) {
        new_cur->next = cur->next;
        new_cur = new_cur->next;
        cur->next = cur->next->next;
        cur = cur->next;
    }

    return dummy.next;
}


int main() {

}