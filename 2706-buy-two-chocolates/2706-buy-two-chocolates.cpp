class Solution {
public:
    int buyChoco(vector<int>& arr, int money) {
        int ans = 1e9;
        int fin;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (i != j ) {
                    int sum = arr[i] + arr[j];
                    ans = min(ans, sum);
                }
            }
        }
       
        fin = money - ans;
        if(fin>=0){
        return fin;
        }
        else{
            return money;
        }
    }
};