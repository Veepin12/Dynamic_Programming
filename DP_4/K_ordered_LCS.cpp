#include <iostream>
using namespace std;

vector<vector<vector<int>>> dp(2003 , vector<vector<int>> (20003, vector<int> ( , -1)));


int LCS(string   s, string t, int n , int m, int i , int j ,int k,vector<vector<vector<int>>>dp ){
    if( n == i || m == j) return 0;
    dp.clear();
    
    if( dp[i][j][k] != -1) return dp[i][j][k];
    int res = 0;
    if( s[i] == t[j]){
        res = 1 + LCS(s , t , n , m, i + 1, j + 1, k , dp);
    }
    else{
        if(k > 0){
            res = 1 + LCS(s , t, n , m , i + 1, j + 1, k -1 , dp);
        }
        res = max( res , LCS( s , t , n , m, i  + 1, j , k , dp));
        res = max( res , LCS( s , t, n ,m ,i , j + 1, k , dp));
    }
    dp[i][j][k] = res;
    return res;
    
   


}


int main(){
    string s;
    getline( cin , s);
    string  t;
    getline( cin , t);
    int k ;
    cin>>k;
    dp.clear();
    cout<<LCS( s , t , s.length() , t.length() , 0 , 0 , k, dp );

    return 0;
}