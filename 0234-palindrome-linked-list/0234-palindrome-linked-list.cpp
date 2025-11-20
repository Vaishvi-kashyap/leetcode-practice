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
        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Step 2: Reverse the second half of the list 1 → 2 → 3 ← 2 ← 1
        ListNode* prev = NULL;
        while (slow != NULL) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Step 3: Compare the first half and the reversed second half
        ListNode* first = head;
        ListNode* second = prev;
        while (second != NULL) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};