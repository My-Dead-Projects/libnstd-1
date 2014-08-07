/**
 * libnstd_test
 *
 * test.cpp
 */

#include "../libnstd/map.h"
#include "catch.hpp"
using std::make_pair;

SCENARIO("map", "[map]") {
    
    GIVEN("a map<int, int>") {
        nstd::map<int, int> map;
        
        REQUIRE(map.size() == 0);
        
        WHEN("a value is inserted") {
            auto result = map.insert(make_pair(0, 5));
            
            REQUIRE(result.second == true);
        }
    }
}
