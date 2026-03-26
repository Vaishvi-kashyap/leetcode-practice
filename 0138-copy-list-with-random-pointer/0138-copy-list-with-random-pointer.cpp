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

        // Step 1: Interleave copied nodes
        Node* oldTemp = head;
        while (oldTemp) {
            Node* newNode = new Node(oldTemp->val);
            newNode->next = oldTemp->next;
            oldTemp->next = newNode;
            oldTemp = newNode->next;
        }

        // Step 2: Assign random pointers
        oldTemp = head;
        while (oldTemp) {
            if (oldTemp->random)
                oldTemp->next->random = oldTemp->random->next;
            oldTemp = oldTemp->next->next;
        }

        // Step 3: Separate the lists
        Node* newHead = head->next;
        Node* newTemp = newHead;
        oldTemp = head;

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