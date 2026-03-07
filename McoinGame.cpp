//
//  MCOINS.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 07/03/26.
//

#include <iostream>
using namespace std;

class solution{
public:
    vector<bool> dp;
    int Mcoin(int n,int k,int l){
        dp[1]=1;
        
        dp[k]=1;
        dp[l]=1;
        if(dp[n]!=0) return dp[n];
        
        for(int i=2;i<=n;i++){
            if(i==k or i==l) continue;
            
            dp[i]=!(dp[i-1] and ((i-k)>=1?dp[i-k]:1) and ((i-l)>=1?dp[i-l]:1));
        }
        
        
        return dp[n];
        
    }
    int optimal(int n,int k,int l){
        dp.clear();
        dp.resize(1000005,-1);
        return Mcoin(n,k,l);
    }
    
};
int main(){
    class solution S;
    cout<<S.optimal(2,3,4);
    return 0;
}
