#include <iostream>
using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;

    int solve( int i, int n, vector<int> & nums){
        if(  i > n) return 0;
        if( dp[i] != -1) return dp[i];
        
        int  temp = nums[i] + solve( i+ 2, n,nums);
        int temp1 = solve( i + 1 , n,nums);

        return dp[i] = max( temp , temp1);







    }

    int rob( vector<int> & nums){
        n = nums.size();
        if( n == 1) return nums[0];
        dp.assign(n + 1,-1);
        int x = solve( 0, n - 2, nums);
        dp.assign( n + 1 , -1);
        int y = solve( 1, n - 1, nums);
        return max(x,y);
        
    }
};
int main(){
    Solution S;
    vector<int> nums = {2,3,2};
    cout<<S.rob(nums)<<endl;
    return 0;
}