#include "Utility.h"


//////////////////////////////////////////////////////
// Math
int utl_fact( int n ) {
    int ret = 1;
    for( int i = 1; i <= n; ++i ) {
        ret *= i;
    }
    return ret;
}

int utl_binarySearchInsert( vector<int>& nums, int target ) {
    // binary search
    unsigned int length = nums.size();

    int start = 0;
    int end = length - 1;
    int mid = 0;
    while( start <= end ) {
        mid = ( start + end ) / 2;
        if( target == nums[mid] ) return mid;
        else if( target < nums[mid] ) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return start;

}

//////////////////////////////////////////////////////
// List
ListNode* utl_genLinkList( vector<int> t_vals ) {
    ListNode sentinel( -1 );
    ListNode* tail = &sentinel;
    for( auto nodeVal : t_vals ) {
        ListNode* newNode = new ListNode( nodeVal );
        tail->next = newNode;
        tail = newNode;
    }

    return sentinel.next;
}


//////////////////////////////////////////////////////
// Tree
// deep copy a tree
TreeNode* utl_tree_deepCopy( TreeNode* t_root ) {
    if( !t_root ) return nullptr;
    TreeNode* ret = new TreeNode( t_root->val );
    ret->left = utl_tree_deepCopy( t_root->left );
    ret->right = utl_tree_deepCopy( t_root->right );
    return ret;
}

// deep copy a tree and add offset for each node
TreeNode* utl_tree_deepCopyAndOffset( TreeNode* t_root, int t_offset ) {
    if( !t_root ) return nullptr;
    TreeNode* ret = new TreeNode( t_root->val + t_offset );
    ret->left = utl_tree_deepCopyAndOffset( t_root->left, t_offset );
    ret->right = utl_tree_deepCopyAndOffset( t_root->right, t_offset );
    return ret;
}



//////////////////////////////////////////////////////
// Heap
// construct the heap from an array

Heap::Heap( const vector<int>& t_arr, HEAP_TYPE t_type ) : _type( t_type ) {
    _arr = t_arr;
    // from the parent of the last leaf
    int i = _parent( ( int )_arr.size() - 1 );
    while( i >= 0 ) {
        _heapify( i );
        --i;
    }
}

// a recursive method to heapify a subtree with root at given index.
// This method assumes that the subtrees are already heapified.
void Heap::_heapify( int i ) {
    int left = _left( i );
    int right = _right( i );

    int rootIdx = i;
    switch( _type ) {
        case MAX_HEAP:
        {
            if( left < (int)GetSize() && _arr[left] > _arr[rootIdx] ) {
                rootIdx = left;
            } 
            if( right < (int)GetSize() && _arr[right] > _arr[rootIdx] ) {
                rootIdx = right;
            }
        } break;
        case MIN_HEAP:
        {
            if( left < (int)GetSize() && _arr[left] < _arr[rootIdx] ) {
                rootIdx = left;
            }
            if( right < (int)GetSize() && _arr[right] < _arr[rootIdx] ) {
                rootIdx = right;
            }
        } break;
        default: return;
    }

    if( rootIdx != i ) {
        // swap root and the largest one 
        int tmp = _arr[i];
        _arr[i] = _arr[rootIdx];
        _arr[rootIdx] = tmp;
        // heapify the subtree
        _heapify( rootIdx );
    }
} 

int Heap::GetRoot() {
    if( GetSize() > 0 ) return _arr.front();
    else {
        assert( true );
        return -1;
    }
}

int Heap::ExtractRoot() {
    if( GetSize() > 0 ) {
        int root = GetRoot();
        if( GetSize() > 1 ) {
            // bring the last one to front
            // and heapify it
            _arr[0] = _arr.back();
            _arr.pop_back();
            _heapify( 0 );
        } else {
            _arr.pop_back();
        }

        return root;
    } else {
        assert( true );
        return -1;
    }
}

void Heap::_siftUp( int i ) {

}

void Heap::Insert( int t_val ) {
    // add new val to end
    _arr.push_back( t_val );
    _siftUp( (int)_arr.size() - 1 );
}

bool Heap::IsEmpty() {
    return _arr.size() == 0;
}

