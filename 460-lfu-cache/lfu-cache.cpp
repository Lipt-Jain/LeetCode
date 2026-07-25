class LFUCache {
    int capacity;
    int minFreq;

    struct Node {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    unordered_map<int, list<Node>> freqList;
    unordered_map<int, list<Node>::iterator> mp;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->value;
        int freq = it->freq;

        freqList[freq].erase(it);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        freqList[freq + 1].push_front(Node(key, value, freq + 1));
        mp[key] = freqList[freq + 1].begin();

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (mp.find(key) != mp.end()) {
            mp[key]->value = value;
            get(key);
            return;
        }

        if (mp.size() == capacity) {
            auto node = freqList[minFreq].back();
            mp.erase(node.key);
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);
        }

        minFreq = 1;
        freqList[1].push_front(Node(key, value, 1));
        mp[key] = freqList[1].begin();
    }
};