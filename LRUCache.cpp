#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

class LRUCache
{
public:
    int capacity;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m;
    std::list<std::pair<int, int>> cache;
    
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        // If doesn't exist in the list
        if (m.find(key) == m.end()) return -1;
        // Move to front
        cache.splice(cache.begin(), cache, m[key]);
        return m[key]->second;
    }

    void put(int key, int value)
    {
        if (get(key) != -1)
        {
            m[key]->second = value;
            return;
        }

        if (cache.size() == capacity)
        {
            const auto last_key{ cache.back().first };
            cache.pop_back();
            m.erase(last_key);
        }
        cache.push_front({ key, value });
        m[key] = cache.begin();
    }

    void show()
    {
        for (const auto& i : cache)
        {
            std::cout << "[" << i.first << ", " << i.second << "]";
        }
        std::cout << std::endl;
    }
};

int main()
{
    LRUCache cache(4);
    cache.put(4, 4);
    cache.put(3, 3);
    cache.put(2, 2);
    cache.put(1, 1);
    cache.show();
    cache.put(5, 5);
    cache.show();
}