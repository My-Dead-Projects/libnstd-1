/**
 * libnstd
 *
 * map.cpp
 */

#include "map.h"

using namespace nstd;
using std::pair;

#define map_template template <class Key, class T, class Compare>
#define map_type map<Key, T, Compare>

map_template
typename map_type::Node *
map_type::recursive_find(const map_type::key_type& key) {
    
}

map_template
pair<typename map_type::iterator, bool>
map_type::insert(const map_type::value_type& value) {
    
}
