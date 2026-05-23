#include <iostream>
using namespace std;


class Solution{
public:

    int unique_path(vector<vector<int>> & nums){
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> dp(1004 , vector<int> ( 883, 0));
        dp.clear();
        dp.resize( n , vector<int> ( m ,0));
        if(nums[n-1][m-1] == 1) return 0;
        dp[n -1][ m  - 1] = 1;

        for( int i = n -2 ; i >= 0; i--){
            if( nums[i][m - 1] == 1) dp[i][m -1] = 0;
            else dp[i][ m- 1] = dp[i + 1][ m- 1];
        }

        for( int  i = m - 2; i >= 0; i++){
            if( nums[n -1][ i] == 1) dp[n -1][i] = 0;
            else dp[n - 1][ i] = dp[ n - 1][ i + 1];
        }
        for( int i = n - 2; i >=0 ; i--){
            if(nums[i][ m- 1] == 1) dp[i][ m- 1] = 0;
            for( int j = m -2; j >= 0; j--){
                
               
                    if( nums[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i  +1][j] + dp[i][ j  + 1];
            }
            
        }
        return dp[0][ 0];
    }

};
int main(){
    vector<vector<int>> nums = {{0,0,0,1},{0,1,0,0}};
    
    Solution S;
    cout<<S.unique_path(nums)<<endl;
    return 0;
}