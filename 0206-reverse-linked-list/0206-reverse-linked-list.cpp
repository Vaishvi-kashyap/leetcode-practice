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
    ListNode* reverseList(ListNode* head) {
        // Base case
        if (head == NULL || head->next == NULL)
            return head;

        // Reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Put current node at the end
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};