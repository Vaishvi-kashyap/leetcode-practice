/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* listA = headA;
        ListNode* listB = headB;
        while (listA != listB) {
            if (listA != NULL)
                listA = listA->next;
            else
                listA = headB;
            if (listB != NULL)
                listB = listB->next;
            else
                listB = headA;
        }
        return listA;
    }
};