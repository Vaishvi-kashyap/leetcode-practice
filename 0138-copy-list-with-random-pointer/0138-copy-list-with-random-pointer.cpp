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
        if(head == NULL)
            return head;
        Node* oldTemp = head;
        while (oldTemp) {
            Node* newTemp = new Node(oldTemp->val);
            newTemp->next = oldTemp->next;
            oldTemp->next = newTemp;
            oldTemp = newTemp->next;
        }

        oldTemp = head;
        while (oldTemp) {
            if (oldTemp->random)
                oldTemp->next->random = oldTemp->random->next;
            oldTemp = oldTemp->next->next;
        }

        oldTemp = head;
        Node* newHead = head->next;
        Node* newTemp = newHead;
        while (oldTemp) {
            oldTemp->next = oldTemp->next->next;
            if (newTemp->next)
                newTemp->next = newTemp->next->next;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};