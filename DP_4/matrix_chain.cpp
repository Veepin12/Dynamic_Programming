#include <iostream>
using namespace std;

vector<vector<int>> dp( 1000, vector<int>( 1000 , -1));
class Solution{
public:

    int f(vector<int> & nums , int i, int n){
        if( i == n || i + 1 == n) return 0;
        int min_val = INT_MAX;
        for( int k =  i + 1; k < n; k++){
            min_val = min({min_val ,f(nums, i, k) + f( nums, k, n) + nums[i] * nums[k] * nums[n]});

        }
        return min_val;
    }

};
int main(){
    Solution S;
    int n ; 
    cin>>n;
    vector<int> nums(n);

    for( int i = 0; i < n; i++) cin>>nums[i];

    
    cout<<S.f(nums , 0 , n - 1)<<endl;
    return 0;
}