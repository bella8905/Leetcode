
#include "Utility.h"


//����n�Ķ����Ʊ�ʾ��1�ĸ��� 
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




