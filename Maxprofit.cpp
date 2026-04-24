//
//  UniquePath2.cpp
//  DS_in_Cpp
//
//  Created by Veepin Chaudhary on 11/02/26.
//

#include <iostream>
#include <vector>
using namespace std;

class solution{
public:
   
    // Iterative Solution Of the MaxProfit into non Consicutie Array;
    int fbu(vector<int> & nums){
        long n=nums.size();
        vector<int> dp(105);
        dp.clear();
        dp.resize(n);
        dp[n-1]=nums[n-1];
        dp[n-2]=max(nums[n-1],nums[n-2]);
        
        for(int i=n-3;i>=0;i--){
            dp[i]+=max(nums[i]+dp[i+2] , 0+dp[i+1]);
            
        }
        return dp[0];
        
        
    }
    
   //iterative solution
    int BottumUp(vector<int> & nums){
         return fbu(nums);
    }
    int robber(vector<int> & nums){
        //Top Down Approhes..
        
        long n= nums.size();
        if(n==1) return nums[0];
        vector<int> dp(105);
        dp[0]=nums[0];  // Dp Intialisation using memorization..
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            dp[i] += max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};


int main(){
    
    class solution S;
    vector<int> nums={2,7,9,3,4,65,4,14};
    cout<<S.robber(nums)<<endl;
    cout<<S.BottumUp(nums)<<endl;
    return 0;
    
    
}
