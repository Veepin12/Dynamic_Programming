#include <iostream>
#include <vector>
using namespace std;
int dp[10005][4][2];
class Solution{
    public:

   

    int f( vector<int> & prices , int i, int k , bool on){
        if( i == prices.size()) return 0;

        if(dp[i][k][on] != -1) return false;

        int ans = INT_MIN;
        ans = f( prices , i + 1, k , on);

        if(on){
            ans = max( ans , f( prices , i + 1, k , false) + prices[i]);

        }
        else{
            if(k > 0){
                ans = max( ans , f( prices , i + 1, k - 1, true) - prices[i]);
            }
        }
        return dp[i][k][on] = ans;

    }
    int profit( int k , vector<int> & prices){
        memset( dp , -1 , sizeof dp);
        return f(prices , 0 , k , false);

    }
    
    

};
int main(){
    Solution S;
    vector<int> prices = { 2 ,4, 1};
    int k = 2;
    cout<<S.profit(2 , prices);
    return 0;
}