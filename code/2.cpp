#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int digit = 0;
    int sum = 0;
    ListNode *result = new ListNode(sum);
    ListNode *first = result;

    while (true) {
        if (l1 == NULL) {
            sum = l2->val + digit;
            l2 = l2->next;
        } else if (l2 == NULL) {
            sum = l1->val + digit;
            l1 = l1->next;
        } else {
            sum = l1->val + l2->val + digit;
            l1 = l1->next;
            l2 = l2->next;
        }

        digit = sum / 10;
        sum %= 10;
        result->val = sum;

        if (l1 == NULL && l2 == NULL)
            break;
        result->next = new ListNode(0);
        result = result->next;
    }
    if (digit != 0)
        result->next = new ListNode(digit);

    return first;
}

ListNode* addTwoNumbers2(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1); // 􏱡􏱖􏱗头节点
    int carry = 0;
    ListNode *prev = &dummy;
    for (ListNode *pa = l1, *pb = l2; pa != nullptr || pb != nullptr;
         pa = pa == nullptr ? nullptr : pa->next,
         pb = pb == nullptr ? nullptr : pb->next,
         prev = prev->next) {
            const int ai = pa == nullptr ? 0 : pa->val;
            const int bi = pb == nullptr ? 0 : pb->val;
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new ListNode(value); // 􏱢􏱣􏰹
        }

    if (carry > 0)
        prev->next = new ListNode(carry);

    return dummy.next;
}


int main() {
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *a1 = addTwoNumbers(l1, l2);
    while (a1 != NULL) {
        cout << a1->val << " ";
        a1 = a1->next;
    }
    cout << endl;


    ListNode *l3 = new ListNode(1);
    l3->next = new ListNode(8);

    ListNode *l4 = new ListNode(0);

    ListNode *a2 = addTwoNumbers(l3, l4);
    while (a2 != NULL) {
        cout << a2->val << " ";
        a2 = a2->next;
    }
    cout << endl;
}