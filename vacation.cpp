#include <iostream>
#include <vector>
using namespace std;


class Solution{

public:
      
    int maxpoint(vector<vector<int>> &days){
        int n = days.size();
        int m = days[0].size();

        vector<vector<int>> dp( n, vector<int> ( 3,0));
        

        dp[0][0] =  days[0][0];
        dp[0][1] =  days[0][1];
        dp[0][2] =  days[0][2];

        for( int i= 1; i < n; i++){
            for(int j =0 ; j< 3; j++){
                dp[i][0] = max({ days[i][0] + max({dp[i-1][1],dp[i-1][2]})});
                dp[i][1] = max({ days[i][1] + max({ dp[i-1][0],dp[i-1][2]})});
                dp[i][2] = max({ days[i][2] + max(dp[i-1][0],dp[i-1][1])});
            }
            
        }
        return max( {dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    }
};
int main(){
    Solution S;
    vector<vector<int>> days={{10,20,30},{10,20,30},{30,20,10}};
    cout<<S.maxpoint(days)<<endl;
    return 0;
    
}