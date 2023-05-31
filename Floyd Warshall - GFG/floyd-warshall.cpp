//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mm){
	    // Code here
	    int n=mm.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(mm[i][j]==-1){
	                mm[i][j]=1e8;
	            }
	            if(i==j){
	                mm[i][j]=0;
	            }
	        }
	    }
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            mm[i][j]=min(mm[i][j],mm[i][k]+mm[k][j]);
	        }
	    }
	    }
	    
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(mm[i][j]==1e8){
	                mm[i][j]=-1;
	            }

	        }
	    }
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends