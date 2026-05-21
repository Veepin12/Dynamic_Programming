#include <iostream>
using namespace std;
vector<int> dp(105 , -1);
class Solution {
    public:

    int mixtures(vector<int> & mixture ){
        int n = mixture.size();
        
        if( n == 1) return 0;
        if( n == 2) return mixture[0] * mixture[1];

        // Resulting Mixture Color a and b is ( a + b) mod 100;
        

        return 3;
    }

    
};
int main(){
    Solution S;

    int n ;
    cin>>n;
    vector<int> mixture(n);
    for( int i = 0;  i < n; i++) cin>>mixture[i];
    
    
    dp.resize(n,0);
    cout<<S.mixtures(mixture  )<<endl;
    cout<<endl;
    return 0;
}