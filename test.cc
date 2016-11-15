#include "llcache.hh"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE llcache
#include <boost/test/unit_test.hpp>

const int NUM_OF_TEST1_RECORDS = 100;
const int NUM_OF_TEST2_RECORDS = 100;
const int TEST2_CACHE_CAPACITY = 50;

BOOST_AUTO_TEST_CASE(SimplePut) {
    llcache<int, int> cache(1);
    cache.insert(7, 777);
    BOOST_CHECK(cache.exists(7));
    BOOST_CHECK_EQUAL(777, cache.lookup(7));
    BOOST_CHECK_EQUAL(1, cache.size());
}

BOOST_AUTO_TEST_CASE(MissingValue) {
    llcache<int, int> cache(1);
    BOOST_CHECK_THROW(cache.lookup(7), std::range_error);
}

BOOST_AUTO_TEST_CASE(KeepsAllValuesWithinCapacity) {
    llcache<int, int> cache(TEST2_CACHE_CAPACITY);

    for (int i = 0; i < NUM_OF_TEST2_RECORDS; ++i) {
        cache.insert(i, i);
    }

    for (int i = 0; i < NUM_OF_TEST2_RECORDS - TEST2_CACHE_CAPACITY; ++i) {
        BOOST_CHECK(not cache.exists(i));
    }

    for (int i = NUM_OF_TEST2_RECORDS - TEST2_CACHE_CAPACITY; i < NUM_OF_TEST2_RECORDS; ++i) {
        BOOST_CHECK(cache.exists(i));
        BOOST_CHECK_EQUAL(i, cache.lookup(i));
    }

    size_t size = cache.size();
    BOOST_CHECK_EQUAL(TEST2_CACHE_CAPACITY, size);
}
