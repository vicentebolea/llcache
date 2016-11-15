# llcache
Minimal C++ LRU cache using a linked-list and a map

- STATUS: [![Build Status](https://travis-ci.org/vicentebolea/llcache.svg?branch=master)](https://travis-ci.org/vicentebolea/llcache)

## DESCRIPTION
This Lru map is using a hashtable+doublylinkedlist where:
 - The hash table will store a pointer of each element in
   the list.
 - The linkedlist will be use as lru linkedlist with a
   pair of key and value.

### TIME COMPLEXITY
Here is described the time complexities of each
functions: 
 - insert:   O(1) (amortized time)
 - lookup:   O(1)

These complexities will be in the best case since 
the hash table will may rehash sometimes and in each 
rehash it will take O(n + buckets).


## AUTHOR 
Vicente Adolfo Bolea Sanchez <vicente.bolea@gmail.com>
