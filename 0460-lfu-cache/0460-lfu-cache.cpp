#include <unordered_map>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    struct DLL {
        Node *head, *tail;
        int size;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        ~DLL() {
            delete head;
            delete tail;
        }

        void add(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node* removeLast() {
            if (size == 0)
                return nullptr;

            Node* node = tail->prev;
            remove(node);
            return node;
        }
    };

    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;

    int capacity;
    int minFreq;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    ~LFUCache() {
        for (auto& it : keyMap)
            delete it.second;

        for (auto& it : freqMap)
            delete it.second;
    }

    int get(int key) {
        auto it = keyMap.find(key);

        if (it == keyMap.end())
            return -1;

        Node* node = it->second;
        update(node);
        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        auto it = keyMap.find(key);

        if (it != keyMap.end()) {
            Node* node = it->second;
            node->value = value;
            update(node);
            return;
        }

        if (keyMap.size() == capacity) {
            DLL* list = freqMap[minFreq];
            Node* removed = list->removeLast();

            keyMap.erase(removed->key);
            delete removed; // Fixed memory leak
        }

        Node* node = new Node(key, value);
        keyMap[key] = node;

        minFreq = 1;

        if (freqMap.find(1) == freqMap.end())
            freqMap[1] = new DLL();

        freqMap[1]->add(node);
    }

private:
    void update(Node* node) {

        int freq = node->freq;
        DLL* list = freqMap[freq];

        list->remove(node);

        if (freq == minFreq && list->size == 0)
            minFreq++;

        node->freq++;

        if (freqMap.find(node->freq) == freqMap.end())
            freqMap[node->freq] = new DLL();

        freqMap[node->freq]->add(node);
    }
};