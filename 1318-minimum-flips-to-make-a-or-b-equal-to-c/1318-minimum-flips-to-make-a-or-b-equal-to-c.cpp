class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = 0;
        while (a || b || c)
        {
            if (c & 1)
            {
                if ((a & 1) == 0 && (b & 1) == 0)
                {
                    d++;
                }
            }
            else
            {
                if (a & 1)
                    d++;
                if (b & 1)
                    d++;
            }
        a >>= 1, b >>= 1, c >>= 1;
        }
    return d;
    }
};