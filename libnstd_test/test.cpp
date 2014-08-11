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
            auto result = map.insert(make_pair(1, 5));
            
            REQUIRE(result.second == true);
            REQUIRE(result.first->first == 1);
            REQUIRE(result.first->second == 5);
            REQUIRE(map.size() == 1);
            
            WHEN("that value is searched for") {
                auto result = map.find(1);
                
                REQUIRE(result->first == 1);
                REQUIRE(result->second == 5);
            }
        }
        
        WHEN("some values are inserted") {
            map.insert(make_pair(1, 5));
            map.insert(make_pair(2, 10));
            map.insert(make_pair(3, 15));
            map.insert(make_pair(4, 20));
            map.insert(make_pair(5, 25));
            
            WHEN("the third value is searched for") {
                auto result = map.find(3);
                
                REQUIRE(result->first == 3);
                REQUIRE(result->second == 15);
            }
            
            WHEN("the fifth value is searched for") {
                auto result = map.find(5);
                
                REQUIRE(result->first == 5);
                REQUIRE(result->second == 25);
            }
        }
    }
}
