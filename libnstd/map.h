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
    
    Node * recursive_find(const key_type& key);
    
public:
    
    class iterator {
        Node * node;
    };
    
    pair<iterator, bool> insert(const value_type& value);
    
};
    
}

#endif
