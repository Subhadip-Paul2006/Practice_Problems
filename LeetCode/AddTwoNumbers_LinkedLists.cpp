// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


#include <iostream>
using namespace std;    
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return dummy -> next;
    }
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    ListNode* tail1 = nullptr;
    ListNode* tail2 = nullptr;

    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (l1 == nullptr) {
            l1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = tail1->next;
        }
    }

    for (int i = 0; i < n2; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (l2 == nullptr) {
            l2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = tail2->next;
        }
    }

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}