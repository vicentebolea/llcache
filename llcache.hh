/**
 * @class  llcache
 * @brief  Template header for llcache ADT
 * @author Vicente Adolfo Bolea Sanchez
 *         <vicente.bolea@gmail.com>,
 *
 **********************************************************
 *
 * @section DESCRIPTION
 * This is just a sketch for the LRU map class.
 *
 * @subsection TIME COMPLEXITY
 * Here is described the time complexities of each
 * functions: 
 *  - insert:   O(1) (amortized time)
 *  - lookup:   O(1)
 *
 * These complexities will be in the best case since 
 * the hash table will may rehash sometimes and in each 
 * rehash it will take O(n + buckets).
 *
 * @subsection METHODOLOGY
 * This Lru map is using a hashtable+doublylinkedlist where:
 *  - The hash table will store a pointer of each element in
 *    the list.
 *  - The linkedlist will be use as lru linkedlist with a
 *    pair of key and value.
 */
#pragma once

#include <stdexcept>
#include <algorithm>
#include <list>
#include <map>

template <class key, class value>
class llcache {
  public:
    llcache(size_t _max) : max (_max) {}
    ~llcache() {}

    void insert(const key& k, const value& v) {
      auto it = ht.find(k);

      if (it == ht.end()) {
        ll.push_back({k, v});
        auto iterator = ll.end();
        ht[k] = --iterator;

      } else {
        auto thepair = *(it->second);
        ll.erase(it->second);
        ll.push_back(thepair);
      }

      if (ht.size() > max) {
        auto it = ll.begin();
        ht.erase(it->first);
        ll.erase(it);
      }
    } 

    const value& lookup(const key& k) {
      auto it = ht.find(k);

      if (it == ht.end()) {
        throw std::range_error("No such key is found in the lru cache");
      }

      return it->second->second;
    }

    bool exists(const key& k) const { 
      return (ht.end() != ht.find(k));
    }

    size_t size() const {
      return ht.size();
    }

  protected:
    size_t max;

    std::list<std::pair<key, value> > ll;
    std::map<key, typename std::list<std::pair<key, value> >::iterator> ht;
};
