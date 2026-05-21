class LRUCache {
public:
    // DLL Node
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;   // key → Node*
    Node* head;                      // dummy head (most recent side)
    Node* tail;                      // dummy tail (LRU side)

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // ---- DLL helpers ----
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // ---- Main functions ----
    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertFront(node);           // move to most recent
        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            deleteNode(mp[key]); //delete from DLL
            delete mp[key]; // delete from map
            mp.erase(key);
        }
        Node* node = new Node(key, value);
        insertFront(node);
        mp[key] = node;
        if (mp.size() > cap) {
            Node* lru = tail->prev;  // LRU is just before dummy tail
            deleteNode(lru); //delete from dll
            mp.erase(lru->key); //delete from map
            delete lru;
        }
    }
};