class LFUCache {
    struct Node {
        int key, value, freq;

        Node(int k, int v, int f)
            : key(k), value(v), freq(f) {}
    };

    int capacity, minFreq;

    unordered_map<int, list<Node>> freqList;
    unordered_map<int, list<Node>::iterator> cache;

    void touch(unordered_map<int, list<Node>::iterator>::iterator it) {
        auto node = it->second;
        int key = node->key;
        int value = node->value;
        int freq = node->freq;

        auto& oldList = freqList[freq];
        oldList.erase(node);

        if (oldList.empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                ++minFreq;
        }

        auto& newList = freqList[freq + 1];
        newList.emplace_front(key, value, freq + 1);
        it->second = newList.begin();
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {
        cache.reserve(capacity * 2);
        freqList.reserve(capacity * 2);
        cache.max_load_factor(0.7f);
        freqList.max_load_factor(0.7f);
    }

    int get(int key) {
        auto it = cache.find(key);

        if (it == cache.end())
            return -1;

        int value = it->second->value;
        touch(it);
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        auto it = cache.find(key);

        if (it != cache.end()) {
            it->second->value = value;
            touch(it);
            return;
        }

        if (cache.size() == capacity) {
            auto& lst = freqList[minFreq];

            int victim = lst.back().key;
            lst.pop_back();

            if (lst.empty())
                freqList.erase(minFreq);

            cache.erase(victim);
        }

        auto& lst = freqList[1];
        lst.emplace_front(key, value, 1);

        cache[key] = lst.begin();
        minFreq = 1;
    }
};
