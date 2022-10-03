/*
https://www.geeksforgeeks.org/position-of-rightmost-set-bit/

The process is:
     
    unsigned int getFirstSetBitPos(int n)
    {
        return log2(n & -n) + 1;
    }
    
    If you take negative of the number (two's complement) and & it with the original #, all the bits except the right most one is set. Then, use log to calculate the bit position.
    
    For instance, n = 100011100
    
    One's complement of n = 011100011
    Two's complement of n = 011100100. This is -n
    
    Now, n & -n = 100.
    
*/
