class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size();
        j--;
        // cout<<j<<endl;
        while(i<j){
            if(i==j) break;
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};