#include <iostream>
using namespace std;

class Solution{
    public:

    int min_path_sum(vector<vector<int>> & nums){

        int n = nums.size();
        int m = nums[0].size();

        int sum = 0;

        vector<vector<int>> dp;
        dp.resize(n , vector<int> (m, 0));

        dp[ n -1][ m - 1] = nums[n- 1][ m -1];

        for( int i = n - 2; i >= 0; i--){
              dp[ i ][ m - 1] += nums[i][m -1]  + dp[i + 1][ m - 1];
            
        }

        for( int i = m - 2; i >= 0; i--){
           dp[n - 1][i] += nums[n -1][i] + dp[ n - 1][ i + 1];
          
        }

        for( int i = n - 2; i >= 0; i--){
            for( int j = m - 2; j >= 0; j--){
                
                    dp[i][j] = nums[i][j] + min( dp[i  + 1][j], dp[ i][ j+ 1]);
                
            }
        }
        return dp[0][0];


    }
};
int main(){
    vector<vector<int>> nums = {{1,3,1},{1,5,1},{4,2,1}};

    Solution S;
    cout<<S.min_path_sum( nums)<<endl;
    return 0;
}