#include <iostream>
using namespace std;
#define ll long long int

class Solution {
public:

    int minTap(int n , vector<int> & range){
    
        vector<ll> dp( n  + 1, INT_MAX);
        
        dp[0] = 0;
        for( int i = 1 ; i <= n; i++){
            int start = max( 0 ,i - range[i]);
            int end = min(i + range[i], n);

            for( int j = start; j <= end ; j++){
                dp[end] = min( dp[end] , dp[j ]+ 1);

            }
        }
        return dp[ n] == INT_MAX? -1 : dp[n];
    }
};
int main(){
    int n ;
    cin>>n;

    vector<int> range(n + 1);
    for( int i = 0 ; i < n + 1; i++) cin>>range[i];
    Solution S;
    cout<<S.minTap(n , range)<<endl;
    return 0;
}