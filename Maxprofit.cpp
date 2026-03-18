#include <iostream>
#include <vector>
using namespace std;
class solution {
    public:
int maxloot(vector<int> & nums){
    int n=nums.size();
    vector<int> dp;
    dp.clear();
    dp.resize(n);

    dp[n-1]=nums[n-1];
    dp[n-2]=max(nums[n-2],nums[n-1]);
    

    for(int i=n-3;i>=0;i--){
        dp[i]+=max(dp[i+2]+nums[i],dp[i+1]);
    }
    return dp[0];
}


};
int main(){
    solution S;
    vector<int> nums={2,7,1,8,5};
    cout<<S.maxloot(nums)<<endl;
    return 0;
}