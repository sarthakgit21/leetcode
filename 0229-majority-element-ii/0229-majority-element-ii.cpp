class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1;
        int num2=-1;
        int c1=0,c2=0;
        for(auto x:nums){
            if(num1==x) c1++;
            else if(num2==x) c2++;
            else if(c1==0){
                num1=x;
                c1=1;
            }
            else if(c2==0){
                num2=x;
                c2=1;
            }
            else c1--,c2--;
            
        }
        int val1=0,val2=0;
        for(auto x:nums){
            if(x==num1){
                val1++;
            }
        }
        
        for(auto x:nums){
            if(x==num2){
                val2++;
            }
        }
        cout<<num1<<" "<<val1<<endl;
        cout<<num2<<" "<<val2<<endl;
        int val=floor(nums.size()/3);
        cout<<val<<endl;
        if(val1>val&&val2>val&&num1!=num2) return {num1,num2};
        if(val1>val) return {num1};
        if(val2>val) return {num2};
        else  return {};
        
    }
};