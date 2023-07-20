class MedianFinder {
public:
    
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==0||right.size()==0){
            left.push(num);
        }
        else{
            if(left.top()<num){
                right.push(num);
            }
            else{
                left.push(num);
            }
        }
        int n=left.size();
        int m=right.size();
        if(abs(m-n)==2){
            if(m>n){
                left.push(right.top());
                right.pop();
            }
            else{
                
                right.push(left.top());
                left.pop();
            }
        }
    }
    
    double findMedian() {
        double ans=0;
          int n=left.size();
        int m=right.size();
        if(n+m&1){
            if(n>m) return left.top();
            return right.top();
        }
        else{
            return ans=(double)((double)left.top()+(double)right.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */