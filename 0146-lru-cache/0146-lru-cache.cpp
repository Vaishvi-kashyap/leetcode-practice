class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void delNode(Node* delNode) {
        Node* oldPrev = delNode->prev;
        Node* oldNext = delNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;

        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            node->val = value;
            delNode(node);
            addNode(node);
            return;
        }

        if (m.size() == limit) {
            Node* lru = tail->prev;
            delNode(lru);
            m.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);
        addNode(node);
        m[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */