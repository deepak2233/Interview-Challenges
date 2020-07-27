class Solution {
public:
    uint32_t reverseBits( uint32_t n ) {
        uint32_t result = 0;
        for( int i = 0; i < 32; i++, n >>= 1 )
            if( n & 1 )
                result |=  1 << ( 31 - i );
        
        return result;
    }
}
