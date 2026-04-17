#include <iostream>
#include <list>
#include <optional>
#include <string>
#include <unordered_map>

template <typename Key, typename Value> class LRUCache
{
  public:
    LRUCache(size_t capacity) : m_capacity(capacity)
    {
    }

    // Lookup and move to front (modifies LRU order). Returns true if found.
    bool get(const Key &key, Value &out)
    {
        auto it = m_index.find(key);
        if (it == m_index.end())
            return false;
        // splice() preserves iterator validity except for evicted items.
        m_items.splice(m_items.begin(), m_items, it->second);
        out = it->second->second;
        return true;
    }

    // Const overload: lookup without modifying LRU order. Returns std::optional<Value>.
    std::optional<Value> get(const Key &key) const noexcept
    {
        auto it = m_index.find(key);
        if (it == m_index.end())
            return std::nullopt;
        return it->second->second;
    }

    void put(const Key &key, const Value &value)
    {
        auto it = m_index.find(key);
        if (it != m_index.end())
        {
            it->second->second = value;
            m_items.splice(m_items.begin(), m_items, it->second);
        }
        else
        {
            m_items.emplace_front(key, value);
            m_index[key] = m_items.begin();
            if (m_items.size() > m_capacity)
            {
                auto lru = m_items.end();
                --lru;
                m_index.erase(lru->first);
                m_items.pop_back();
            }
        }
    }

    void display() const noexcept
    {
        std::cout << "Cache state: ";
        for (const auto &pair : m_items)
        {
            std::cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        std::cout << '\n';
    }
    size_t size() const noexcept
    {
        return m_items.size();
    }
    size_t capacity() const noexcept
    {
        return m_capacity;
    }
    void clear() noexcept
    {
        m_items.clear();
        m_index.clear();
    }
    bool contains(const Key &key) const noexcept
    {
        return m_index.find(key) != m_index.end();
    }

    /*
     * Invariants:
     * - splice() preserves iterator validity except for evicted items.
     * - Only eviction (pop_back) invalidates iterators to the evicted item.
     * - get(const Key&, Value&) modifies LRU order; get(const Key&) const does not.
     * - All non-throwing functions are marked noexcept where reasonable.
     */

  private:
    size_t m_capacity;
    std::list<std::pair<Key, Value>> m_items;
    std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> m_index;
};

int main()
{
    LRUCache<std::string, int> cache(3);
    cache.put("A", 1);
    cache.put("B", 2);
    cache.put("C", 3);
    cache.display();

    int value;
    if (cache.get("B", value))
    {
        std::cout << "Get B: " << value << '\n';
    }
    cache.display();

    cache.put("D", 4);
    cache.display();

    if (cache.get("C", value))
    {
        std::cout << "Get C: " << value << '\n';
    }
    cache.display();

    cache.put("A", 5);
    cache.display();

    return 0;
}