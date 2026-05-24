#include <iostream>
#include <set>
using namespace std;

class Solution{
public:

    // path form ( 0 , 0) -> ( n - 1,m - 1).
    vector<vector<int>> min_val(vector<vector<int>> & nums){
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> dp;
        dp.clear();
        dp.resize(n, vector<int> (m,0));

        dp[0][0] = nums[0][0];

        for( int i = 1; i < n; i++){// fill first row..
            dp[i][0] = nums[i][0] + dp[i - 1][0];
        }

        for( int j = 1; j < m; j++){// fill the first column...
            dp[0][j] = nums[0][j] + dp[ 0][ j - 1];
        }
        for( int i = 1; i < n; i++){// fill the index value ....2
            for( int j = 1; j < m; j++){
                dp[i][j] = nums[i][j] + min(dp[i - 1 ][j], dp[i][j- 1]);
            }
        }
        return dp;

    }
    vector<vector<int>>  min_val1(vector<vector<int>> & nums){
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> dp;
        dp.clear();
        dp.resize(n, vector<int> (m,0));

        dp[ n - 1][0] = nums[ n - 1][0];

        for( int i =  n - 2; i >= 0; i--){// fill bottum left column..
            dp[ i][ 0] = nums[i][ 0] + dp[i + 1][0];
        }

        for( int j = 1; j < m; j++){// fill bottum down rows..
            dp[ n - 1][ j] = nums[ n - 1][j] + dp[ n - 1][ j - 1];
        }
        for( int i = n - 2; i >= 0; i--){// fill the index value ....2
            for( int j = 1; j < m; j++){
                dp[i][j] = nums[i][j] + min(dp[i + 1 ][j], dp[i][j- 1]);
            }
        }
        return dp;

    }

    set<pair<int, int>> set_value1( vector<vector<int>> & dp1){
        int i = 0;
        int j = 0;
        int n = dp1.size();
        int m = dp1[0].size();

        set<pair<int ,int>> path;
        path.insert({i , j});
        while( i != 0  || j != 0) {
            if( i ==  n - 1) j++;
            else if ( j == m -1) i++;
            else if( dp1[i + 1][j] < dp1[ i][ j + 1] ) i++;
            else j++;
            path.insert({i ,j});
        }
        return path;

    }

    set<pair<int, int>> set_value2( vector<vector<int>> & dp2){
        int n = dp2.size();
        int m = dp2[0].size();

        int i =  n - 1;
        int j =  0;
        

        set<pair<int ,int>> path;
        path.insert({i , j});
        while( i != 0 || j != m - 1) {
            if( i ==  0) j++;
            else if ( j == m -1) i--;
            else if( dp2[i - 1][j] < dp2[i][ j + 1] ) i--;
            else j++;
            path.insert({i ,j});
        }
        return path;

    }

    
  
    int common_path(vector<vector<int>> &nums){

        vector<vector<int>> dp1 = min_val(nums);
        vector<vector<int>> dp2 = min_val1(nums);

        set<pair<int, int>> path1 = set_value1(dp1);
        set<pair<int, int>> path2 = set_value2(dp2);

        int sum = 0;

        for( auto const & ele  : path1){
            sum += nums[ele.first][ele.second];
        }
        for( auto const & ele : path2){
            if( path1.find(ele) == path1.end()){
                sum += nums[ele.first][ele.second];
            }
        }
        return sum;
    }

};
int main(){
    vector<vector<int>> nums = {{1,2},{3,4}};
    Solution S;
/*
[ 1 ,  2]
[ 3 ,  4]
path for (0 , 0) :    2->2->1.
path for ( n - 1, 0) : 2->1->3.
 */

    cout<<"The combinational Sum : " <<S.common_path(nums)<<endl;

    return 0;
}