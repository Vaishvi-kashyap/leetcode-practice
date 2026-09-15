class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
private:
    Node* head = NULL;

public:
    MyLinkedList() { head = NULL; }

    int get(int index) {
        if (index < 0)
            return -1;
        Node* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            if (cnt == index)
                return temp->val;
            temp = temp->next;
            cnt++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL)
            head = newNode;
        else if (head != NULL) {
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index < 0)
            return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            if (index == NULL)
                return;
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        if (temp == NULL)
            return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0)
            return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            if (temp == NULL)
                return;
            temp = temp->next;
        }
        if (temp->next == NULL)
            return;
        Node* newNode = temp->next;
        temp->next = temp->next->next;
        delete newNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */