class AllOne {
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;

        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unordered_map<string, Node*> mp;

    void insertAfter(Node* p, Node* node) {
        node->next = p->next;
        node->prev = p;
        p->next->prev = node;
        p->next = node;
    }

    void eraseNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        mp.reserve(50000);
        mp.max_load_factor(0.7f);
    }

    void inc(string key) {
        auto it = mp.find(key);

        if (it == mp.end()) {
            Node* node = head->next;

            if (node == tail || node->count != 1) {
                node = new Node(1);
                insertAfter(head, node);
            }

            node->keys.insert(key);
            mp.emplace(std::move(key), node);
            return;
        }

        Node* cur = it->second;
        Node* nxt = cur->next;
        int newCount = cur->count + 1;

        if (nxt == tail || nxt->count != newCount) {
            nxt = new Node(newCount);
            insertAfter(cur, nxt);
        }

        nxt->keys.insert(key);
        it->second = nxt;

        cur->keys.erase(key);

        if (cur->keys.empty())
            eraseNode(cur);
    }

    void dec(string key) {
        auto it = mp.find(key);
        Node* cur = it->second;
        int newCount = cur->count - 1;

        if (newCount == 0) {
            mp.erase(it);
        } else {
            Node* prv = cur->prev;

            if (prv == head || prv->count != newCount) {
                prv = new Node(newCount);
                insertAfter(cur->prev, prv);
            }

            prv->keys.insert(key);
            it->second = prv;
        }

        cur->keys.erase(key);

        if (cur->keys.empty())
            eraseNode(cur);
    }

    string getMaxKey() {
        return tail->prev == head
            ? "" : *tail->prev->keys.begin();
    }

    string getMinKey() {
        return head->next == tail
            ? "" : *head->next->keys.begin();
    }
};