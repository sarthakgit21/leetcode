class Solution {
public:
    int divide(int dividend, int divisor) {
        long double x=(long)dividend/(long)divisor;
        if(x>INT_MAX) return INT_MAX;
        if(x<INT_MIN) return INT_MIN;
        return int(x);
    }
};