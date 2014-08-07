/**
 * libnstd
 *
 * map.h
 */

#ifndef libnstd_map_h
#define libnstd_map_h

#include <functional>
using std::pair;

namespace nstd {
    
template <class Key, class T, class Compare = std::less<Key>>
class map {
public:
    
    typedef pair<Key, T> value_type;
    typedef Key key_type;
    typedef T mapped_type;
    
private:
    
    class Node {
    public:
        value_type value;
        Node * lnode;
        Node * rnode;
    } * node;
    
    size_t _size;
    
    Node * recursive_find(const key_type& key);
    
public:
    
    class iterator {
        Node * node;
    };
    
    pair<iterator, bool> insert(const value_type& value);
    
    size_t size();
    
};

}

/****************************************************/
/**************** Method Definitions ****************/
/****************************************************/

#define map_template template <class Key, class T, class Compare>
#define map_type nstd::map<Key, T, Compare>
#define map_typename typename map_type

map_template
map_typename::Node *
map_type::recursive_find(const map_type::key_type& key) {
    
}

map_template
pair<map_typename::iterator, bool>
map_type::insert(const map_type::value_type& value) {
    
}

map_template
size_t map_type::size() {
    return _size;
}

#undef map_template
#undef map_type
#undef map_typename

#endif
