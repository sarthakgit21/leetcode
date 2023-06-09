class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(),letters.end());
        for(auto x:letters){
            if(x!=target&&x>target) return x;
        }
        return letters[0];
    }
};