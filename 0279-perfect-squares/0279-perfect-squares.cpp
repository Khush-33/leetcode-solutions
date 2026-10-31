class Solution {
public:
    bool square(int n){
        int r = round(sqrt(n));
        return r*r == n;
    }
    int numSquares(int n) {
        // check if n is a perfect square
        if(square(n)) return 1;

        // check legendre's three square thm 4^a *(8b+7)
        int temp =n;
        while(temp%4==0) temp /= 4;
        if(temp%8 == 7) return 4;

        // check if n can be written as the sum two squares
        for(int i=1;i*i <= n;++i){
            if(square(n-i*i)) return 2;
        }
        //otherwise the answer is 3;
        return 3;
    }
};