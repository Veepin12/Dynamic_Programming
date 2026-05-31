#include<iostream>
using namespace std;




int dp[10002][103][2];

int f(vector<int> & prices , int i ,int k , bool on){
    if( i == prices.size()) return 0;
    if( dp[i][k][on] != -1) return dp[i][k][on];
    int ans = INT_MIN;

    ans = f(prices , i + 1 , k, on) ; // avoid 

    if( on){
        ans = max( ans , prices[i] + f( prices , i 
            + 1, k - 1, false));

    }
    else{
        if( k > 0){
            ans = max( ans ,  f(prices , i + 1, k , true) - prices[i]);
        }
    }
    return dp[i][k][on] = ans;

}
int profit( int k ,vector<int> & prices){
    memset( dp , -1, sizeof dp);
    return f( prices, 0 , k , false);

}
int main(){
    
    
    vector<int> prices = { 2 , 4, 1};
    int k = 2;
  

    cout<<profit(k , prices)<<endl;
    return 0;
}