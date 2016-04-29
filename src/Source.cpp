
#include "Utility.h"


//计算n的二进制表示中1的个数 
inline int count1( unsigned int n ) {
    int r = 0;
    while( n ) {
        n &= n - 1;
        r++;
    }
    return r;
}


int main() {

	int  ret = count1( 4 );
    return 0;
}




