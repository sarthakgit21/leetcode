class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        s+='1';
        s=s.substr(1);
        return s;
    }
};