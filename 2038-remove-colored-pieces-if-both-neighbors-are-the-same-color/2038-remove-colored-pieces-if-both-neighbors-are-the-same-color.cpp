class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0;
        int b=0;
        int x=0;
        int y=0;
        // colors+="AB";
        // colors+='B';
        for(auto c:colors)
        {
            if(c=='B'){
                if(x>2){
                    a+=(x-2);
                }
                cout<<x;
                x=0;
                y++;
            }
            else if(c=='A'){
                if(y>2){
                    b+=(y-2);
                }
                y=0;
                x++;
            }
            
        }
        if(x>2) a+=(x-2);
        if(y>2) b+=(y-2);
        return a>b;
        
    }
};