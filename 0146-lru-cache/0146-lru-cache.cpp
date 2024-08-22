#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        // Move the accessed item to the front of the list
        items.splice(items.begin(), items, it->second.second);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Update the value and move the item to the front of the list
            it->second.first = value;
            items.splice(items.begin(), items, it->second.second);
        } else {
            if (items.size() == capacity) {
                // Remove the least recently used item
                cache.erase(items.back());
                items.pop_back();
            }
            items.push_front(key);
            cache[key] = {value, items.begin()};
        }
    }

private:
    int capacity;
    std::list<int> items;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
};
