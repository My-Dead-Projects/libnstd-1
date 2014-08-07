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
        Node(const value_type&);
    } * node;
    
    size_t _size;
    
    Node * recursive_find(const key_type& key);
    
public:
    
    class iterator {
        Node * node;
    public:
        iterator(Node *);
        value_type& operator * ();
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

/**
 * Public methods
 */
map_template
pair<map_typename::iterator, bool>
map_type::insert(const map_type::value_type& value) {
    if (node == nullptr) {
        node = new Node(value);
        return std::make_pair(iterator(node), true);
    } else {
        return std::make_pair(iterator(nullptr), false);
    }
}

map_template
size_t map_type::size() {
    return _size;
}

/**
 * Private methods
 */
map_template
map_typename::Node *
map_type::recursive_find(const map_type::key_type& key) {
    
}

/**
 * Iterator
 */
map_template
map_typename::value_type& map_type::iterator::operator * () {
    return node->value;
}

map_template
map_type::iterator::iterator(map_type::Node * n) {
    node = n;
}

/**
 * Node
 */
map_template
map_type::Node::Node(const map_type::value_type& v) : value(v) {
    
}

#undef map_template
#undef map_type
#undef map_typename

#endif
