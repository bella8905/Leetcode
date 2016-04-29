#pragma once


#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <bitset>
#include <limits>
#include <functional>

using std::vector;
using std::string;
using std::set;
using std::unordered_map;
using std::unordered_set;
using std::pair;
using std::stack;
using std::priority_queue;
using std::min;
using std::max;
using std::numeric_limits;
using std::bitset;

//////////////////////////////////////////////////////
// List
struct ListNode {
    int val;
    ListNode *next;
    ListNode( int x ) : val( x ), next( nullptr ) {}

};








//////////////////////////////////////////////////////
// Tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}

};





//////////////////////////////////////////////////////
// Heap
// construct the heap from an array
class Heap {
public:
    enum HEAP_TYPE { MIN_HEAP, MAX_HEAP };

public:
    Heap( const vector<int>& t_arr = {}, HEAP_TYPE t_type = MIN_HEAP );
    ~Heap() {}

private:
    HEAP_TYPE _type;
    // a pointer the the original array
    vector<int> _arr;

private:
    // heapify subtree rooted with index i
    // sift down the element at i to leaf
    void _heapify( int i );
    // sift up the element at i to root
    void _siftUp( int i );
    int _parent( int i ) { return ( i - 1 ) / 2; }
    int _left( int i ) { return i * 2 + 1;  }
    int _right( int i ) { return i * 2 + 2; }
    
public:
    // get min/max
    int GetRoot();
    // extract the root
    int ExtractRoot();
    // insert a key
    void Insert( int t_val );
    bool IsEmpty();
    unsigned int GetSize() { return _arr.size(); }
};