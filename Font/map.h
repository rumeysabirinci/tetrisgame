#pragma once

#include <utility>
#include "vector.h"
using namespace std;
template <typename Key, typename Value>
class Map {
public:
    void insert(const pair<Key, Value>& entry);
    Value& operator[](const Key& key);
    bool contains(const Key& key) const;

private:
    Vector<pair<Key, Value>> entries;
};

template <typename Key, typename Value>
void Map<Key, Value>::insert(const std::pair<Key, Value>& entry) {
    entries.push_back(entry);
}

template <typename Key, typename Value>
Value& Map<Key, Value>::operator[](const Key& key) {
    for (auto& entry : entries) {
        if (entry.first == key) {
            return entry.second;
        }
    }

    // Create a new entry if the key is not found
    entries.emplace_back(key, Value{});
    return entries.back().second;
}

template <typename Key, typename Value>
bool Map<Key, Value>::contains(const Key& key) const {
    for (const auto& entry : entries) {
        if (entry.first == key) {
            return true;
        }
    }
    return false;
}
