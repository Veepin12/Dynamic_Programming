#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
double dp[3005][3005];

double f( vector<double> & p , int i , int x){
    if(  x == 0) return 1;
    if( i == -1) return 0;
    if (dp[i][x] > -0.9) return dp[i][x];
    return dp[i][x] = f( p , i - 1 , x - 1) * p[i] + f(p , i - 1, x)*( 1 - p[i]);

    
}
int main(){
    int N ;
    cin>>N;
    
    vector<double> p(N);

    for( int i = 0; i < N; i++){
        cin>>p[i];
    }

    
    memset(dp , -1 , sizeof dp);
    cout<<fixed<<setprecision(9)<<f( p , N - 1 , (N  + 1) / 2);
    return 0;
}