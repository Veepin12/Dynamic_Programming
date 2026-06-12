#include <iostream>
using namespace std;

int max_Area( vector<vector<int>> & nums){

    int n = nums.size();
    int m = nums[0].size();
    int maxArea = 0;

    vector<vector<int>> dp(n + 1, vector<int> (m + 1,0));

    for( int i = 1; i <= n ; i++){
        for( int j = 1; j <=m; j++){
            if( nums[i- 1][j -1] == 1){
                dp[i][j] = min({ dp[i -1][j],dp[i][j -1] ,dp[i - 1][j -1]}) + 1;
                maxArea = max( maxArea,dp[i][j]);

            }
        }
    }
    return maxArea * maxArea;
}
int main(){
    vector<vector<int>> nums = {{1,1,0,0},{1,1,0,0},{1,1,0,0},{1,1,0,0}};
    cout<<max_Area(nums)<<endl;
    return 0;
}