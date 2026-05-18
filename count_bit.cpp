//
//  binary.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 17/05/26.

// Time Complexity = O(nlogn).
// Space = O(n) for vector.

#include <iostream>
using namespace std;

int count( int n){
    if(n == 0) return 0;
    
    int count1 = 0;
    string s = "";
    while( n > 0){
        s = (char)( '0' + n % 2 ) + s;
        n/=2;
    }
    for( int i = 0; i < s.length(); i++){
        if(s[i] == '1') count1++;
    }
    return count1;
}

vector<int> countBits(int n){
        
        vector<int> ans;

        for( int i = 0; i <=n; i++){
            int val = count(i);
            ans.push_back(val);
        }
     return ans;
}
int main(){
    cout<<count(5)<<endl;
    
    vector<int> res = countBits(20);
    for( int i =0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
