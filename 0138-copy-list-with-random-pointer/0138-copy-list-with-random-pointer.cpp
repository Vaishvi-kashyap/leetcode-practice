/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return head;
        Node* oldtemp = head;
        while (oldtemp) {
            Node* newnode = new Node(oldtemp->val);
            newnode->next = oldtemp->next;
            oldtemp->next = newnode;
            oldtemp = newnode->next;
        }

        oldtemp = head;
        while (oldtemp) {
            if (oldtemp->random)
                oldtemp->next->random = oldtemp->random->next;
            oldtemp = oldtemp->next->next;
        }

        Node* newhead = head->next;
        Node* newtemp = newhead;
        oldtemp = head;
        while (oldtemp) {
            oldtemp->next = oldtemp->next->next;
            if (newtemp->next)
                newtemp->next = newtemp->next->next;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        return newhead;
    }
};