//
//  mixture.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 21/05/26.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
#define ll long long int





vector<vector<int>> dp(102, vector<int> (105,-1));


    
    ll g(vector<int> & nums , int i , int j){
        ll result = 0;
        for( int k = i; k <= j; k++){
            result = (result % 100 + nums[k] % 100 ) % 100;
        }
        return result;
    }
    
    ll f(vector<int> & nums, int i , int a ){
        if( i == a ) return 0;
        if(dp[i][a] != -1) return dp[i][a];
        ll result = INT_MAX;
        
        for( int k = i ; k <= a -1; k++){
            result = min(result , f( nums,i ,k) + f( nums,k + 1 ,a) + g(nums,i,k) * g( nums, k + 1 ,a) );
        }
        return dp[i][a] = result;
        
        
        
}



int main(){
   
    int n ;
    
    while(cin>>n){
        vector<int> nums;
        for( int i = 0; i < n; i++){ 
            
            int a ;
            cin>>a;
            nums.push_back(a);
        }
        cout<<f(nums,0, nums.size() -1)<<endl;
        nums.clear();
        break;
    }
    

   
    return 0;
}

