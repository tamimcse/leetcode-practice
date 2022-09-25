/*
https://practice.geeksforgeeks.org/problems/geek-and-coffee-shop5721/1/?company[]=Amazon&company[]=Amazon&page=1&query=company[]Amazonpage1company[]Amazon
*/

    //solved in geekforgeeks.com
    int mthHalf(int N, int M){
        int i;
        
        while (M > 31) {
            N = N >> 31;
            M = M - 31;
            
        }
        return N >> (M - 1);
    }
