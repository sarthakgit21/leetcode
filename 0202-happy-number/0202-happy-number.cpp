class Solution {
public:
    int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
    bool isHappy(int n) {
        int N=n;
        unordered_set<int> st;
        while(N!=1&&!st.count(N))
        {
            st.insert(N);
            N=nextNumber(N);
        }
        return N==1;
        
    }
};