#include <iostream>
using namespace std;

class Solution {
public:
     
    vector<int> dp;
    int f( int n  ){
        if( n == 0 || n == 1) return 1;
        if ( n == 2) return 2;
        if(dp[ n] != -1) return dp[n];
        int sum = 0;
        for( int i = 1; i <= n; i++){
            sum += f(i -1) * f( n - i);
        }
        return dp[n] = sum;
    }
    int no_of_structure(int n){
        
        dp.clear();
        dp.resize(30 , - 1);
        return dp[n] = f( n);
    }
    

    // Bottum up Solution ..

    int numTrees( int n){
        dp.clear();
        dp.resize(30, -1);
    
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for( int i = 3; i <= n; i++){
            dp[i] += f( i - 1) * f(n - i);
        }
        return dp[n];

    }


};
int main(){
    int n ;
    cin>>n;
    Solution S;

    //cout<<S.no_of_structure(n)<<endl;
    cout<<S.numTrees(n)<<endl;
    return 0;
}