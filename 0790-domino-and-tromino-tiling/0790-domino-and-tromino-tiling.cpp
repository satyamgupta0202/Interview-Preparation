class Solution {
public:
    int numTilings(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 5;
        //a = n(1), b = n(2), c = n(3)
        long res, a = 1, b = 2, c = 5;
        while(n-- > 3) {
            res = (2*c + a) % int (1e9 + 7);
            a = b;
            b = c;
            c = res;
        }
        return res;
    }
};