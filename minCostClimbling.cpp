//
//  MinCostClimbing.cpp
//  DS_in_Cpp
//
//  Created by Veepin Chaudhary on 11/02/26.
//

#include <iostream>
#include <vector>
using namespace std;
class solution{
public:
    
    int helper(vector<int> & cost,int i,int sum,vector<int> & dp){
        if(i==1 || i==0) return sum+cost[i];
        if(dp[i]!=-1) return dp[i];
        dp[i]=min(helper(cost,i+1,sum+cost[i+1],dp),helper(cost,i+2,sum+cost[i],dp));
        return dp[i];
    }
    int MinCost(vector<int> & cost){
       
        long n=cost.size();
        for(int i=2;i<n;i++){
            cost[i]+=min(cost[i-1],cost[i-2]);
            
        }
        // Bottom Up approaches...
        return min(cost[n-1],cost[n-2]);
    }
    
    int MC(vector<int> & cost,long n,vector<int> & dp){
        dp[n-1]=cost[n-1];
        dp[n-2]=min(cost[n-1],cost[n-2]);
        for(long i=n-3;i>=0;i--){
            dp[i] += min(cost[i-2] , cost[i-1]);
        }
        return dp[0];
    }
};
int main(){
    
    // It is very Important to verify problems.Its is DP or Greedy.
    class solution S;
    vector<int> cost={1,100,1,100,100,100,1,1};
    long n=cost.size();
    vector<int> dp(n,-1);
    
    cout<<S.MinCost(cost)<<endl;
    cout<<S.helper(cost,0,0,dp)<<endl;
    
    cout<<S.MC(cost,n,dp)<<endl;
    return 0;
}
