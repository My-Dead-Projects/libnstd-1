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
        
        WHEN("two values are inserted") {
            map.insert(make_pair(1, 5));
            auto result = map.insert(make_pair(2, 10));
            
            REQUIRE(result.second == true);
            REQUIRE(result.first->first == 2);
            REQUIRE(result.first->second == 10);
            REQUIRE(map.size() == 2);
            
            WHEN("the second value is searched for") {
                auto result = map.find(2);
                
                REQUIRE(result->first == 2);
                REQUIRE(result->second == 10);
            }
        }
    }
}
