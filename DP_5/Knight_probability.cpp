#include <iostream>
using namespace std;
#include <iomanip>
double dp[30][30][105];

class Solution {
        double f( int n ,int i, int j , int k){
            
            if( i < 0 || j < 0 || j >= n || i >= n) return 0;
            if( k == 0) return 1;
            
            if( dp[i][j][k] > -0.9) return dp[i][j][k];

            double ans = 0.0;
            ans += f( n , i + 1, j + 2, k - 1)* (0.125) ;
            ans += f( n , i + 2, j + 1, k - 1)* (0.125) ;
            ans += f( n , i + 1, j - 2, k - 1)* (0.125) ;
            ans += f( n , i + 2, j - 1, k - 1)* (0.125) ;
            ans += f( n , i - 1, j + 2, k - 1)* (0.125) ;
            ans += f( n , i - 2, j + 1, k - 1)* (0.125) ;
            ans += f( n , i - 1, j - 2, k - 1)* (0.125) ;
            ans += f( n , i - 2, j - 1, k - 1)* (0.125) ;
            
            

           return dp[i][j][k] = ans ;
         
            
        }
    public:
       double Knight(int n , int k , int row , int col){
        memset( dp , - 1, sizeof dp);
        
        return f(n ,row , col , k);
    



    }
};
int main(){
    int n; 
    cin>>n;
    int k ;
    cin>>k;
    int row ;
    cin>>row;
    int col;
    cin>>col;
    Solution S;
    

    cout<<fixed<<setprecision(8)<<S.Knight(n, k, row, col)<<endl;

    return 0;
}