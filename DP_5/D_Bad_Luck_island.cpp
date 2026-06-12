#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

double dp[105][105][205];

double rock( int r , int s , int p ){
        
    if(r == 0 || s == 0) return 0;

    if(p == 0) return 1;
   
   
    if( dp[r][s][p] > -0.9) return dp[r][s][p];
    double ans = 0.0;
    ans += rock(r - 1, s, p) * ( r * p)/( r*s + s* p + p* r);
    ans += rock(r , s - 1, p) * ( r * s)/( r*s + s* p + p* r);
    ans += rock(r , s, p - 1) * (  s * p)/( r*s + s* p + p* r);
    return dp[r][s][p] =  ans;
    



}
double scissior( int r , int s , int p ){

    if(s == 0 || p == 0) return 0;
    if(r == 0) return 1;
   
   
    if( dp[r][s][p] > -0.9) return dp[r][s][p];
    double ans = 0;
    ans += scissior(r - 1, s, p) * ( r * p)/( r*s + s* p + p* r);
    ans += scissior(r , s - 1, p) * ( r * s)/( r*s + s* p + p* r);
    ans += scissior(r , s, p - 1) * (  s * p)/( r*s + s* p + p* r);
    return dp[r][s][p] =  ans;
    
    


}
double paper( int r , int s , int p ){

     if(r == 0 || p == 0) return 0;
   
    if(s == 0) return 1;
   
    if( dp[r][s][p] > -0.9) return dp[r][s][p];
    double ans = 0;
    ans += paper(r - 1, s, p) * ( r * p)/( r*s + s* p + p* r);
    ans += paper(r , s - 1, p) * ( r * s)/( r*s + s* p + p* r);
    ans += paper(r , s, p - 1) * (  s * p)/( r*s + s* p + p* r);
    return dp[r][s][p] =  ans;
    
    


}

int main(){
    

    int r, s , p;
    cin>>r>>s>>p;

    
    memset( dp , - 1.0, sizeof dp);

    cout<<fixed<<setprecision(9)<<rock(r , s , p )<<endl;
    memset( dp , - 1, sizeof dp);

    cout<<scissior(r, s, p)<<endl;
    memset( dp , - 1, sizeof dp);
    cout<<paper(r , s, p)<<endl;

    return 0;
}