//
//  Unique.cpp
//  DS_in_Cpp
//
//  Created by Veepin Chaudhary on 11/02/26.
//

#include <iostream>
using namespace std;

int helper(int sr ,int sc,int er ,int ec,vector<vector<int>> &dp){
    if(sr==er && sc==ec) return 1;
    if(sr>er || sc>ec) return 0;
    if(dp[sr][sc]!=-1) return dp[sr][sc];
    dp[sr][sc]=helper(sr,sc+1,er,ec,dp)+ helper(sr+1,sc,er,ec,dp);
    
    return dp[sr][sc];
    
}
int uniquepath(int m,int n){
   
    vector<vector<int> > dp(m,vector<int>( n,-1));
    return helper(0,0,m-1,n-1,dp);
    
}
int Uniquepath1(int m,int n){
    
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0) dp[i][j]=1;
               else  dp[i][j]=(dp[i-1][j] + dp[i][j-2]);
                
            
        
    }
    
    
    }
    return dp[m-1][n-1];
}

int main(){
    int m=3,n=7;

    cout<<uniquepath(m,n)<<endl;
    cout<<Uniquepath1(m,n)<<endl;
    return 0;
    
    
}
