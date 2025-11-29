/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int sum = 0, carry = 0;
        while (l1 != NULL || l2 != NULL) {
            sum = carry;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum %= 10;
            cout << "carry: " << carry << " sum: " << sum << endl;

            ListNode* res = new ListNode(sum);
            temp->next = res;
            temp = temp->next;
        }
        if (carry == 1) {
            temp->next = new ListNode(1);
        }
        return dummy->next;
    }
};