class Solution {
public:
    int getSum(int a, int b) {
        
        while(a!=0)
        {
            int c=b;
            b=a^b;
            a=a&c;
            a=a<<1;
        }
        return b;
        
    }
};