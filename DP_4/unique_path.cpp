#include <iostream>
using namespace std;

class Solution{
public:
    
    int unique_path(int n , int m){
        

        vector<vector<int>> dp( n, vector<int> ( m, 0));
        dp[0][0] = 1;

        for( int i = 0; i < n ;i++){// fill the upper column wit 1.
            dp[i][ 0] = 1;
        }

        for( int i = 0; i < m ;i++){// fill the first row with 1.
            dp[ 0][ i] = 1;
        }

        for( int i = 1; i < n; i++){
            for( int j = 1; j < m; j++){
                dp[i][j] = dp[i - 1][j] + dp[ i][ j - 1];
            }
        }
        return dp[n - 1][ m- 1];
    }
};
int main(){
    Solution S;
    int n ; 
    cin>>n;
    int m ;
    cin>>m;
   
    cout<< S.unique_path( n , m);
    return 0;
}