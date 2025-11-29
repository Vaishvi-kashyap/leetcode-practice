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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow)
            cout << slow->val << endl;

        ListNode* prev = NULL;
        while (slow != NULL) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        slow = head;
        fast = prev;
        while (fast != NULL) {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};