//
//  Min_count_station.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 16/05/26.
//


#include <iostream>
using namespace std;

class Solution1{
public:
    
    int minCount( int target, int startlimit,vector<vector<int>> & stations){
        
        int n = stations.size();
        vector<int> dp(n + 1, 0);
        dp[0] = startlimit;
        
        for( int i = 0; i < n; i++){
            for( int j = i; j >= 0; j--){
                if(dp[j] >= stations[i][0])
                    dp[j+1] = max(dp[j + 1],dp[j] + stations[i][1]);
            }
        }
        for( int i =0; i < n; i++){
            if(dp[i]>= target) return i;
        }
        
        
        return -1;
    }
    
};
class Solution {
public:
     int minRefuelStops(int target, int tank, vector<vector<int>> &stations) {
        // pq is a maxheap of gas station capacities
        priority_queue<int> pq ;
        int ans = 0, prev = 0;
        for (auto station: stations) {
            int location = station[0];
            int capacity = station[1];
            tank -= location - prev;
            while (!pq.empty() && tank < 0) {  // must refuel in past
                tank += pq.top();
                pq.pop();
                ans++;
            }

            if (tank < 0) return -1;
            pq.push(capacity);
            prev = location;
        }

        // Repeat body for station = (target, inf)
        {
            tank -= target - prev;
            while (!pq.empty() && tank < 0) {
                tank += pq.top();
                pq.pop();
                ans++;
            }
            if (tank < 0) return -1;
        }

        return ans;
    }
};

int main(){
    Solution S;
    
    vector<vector<int>> stations = {{25,30}};
    int target = 100;
    int tank = 50;
    Solution1 S1;
    cout<<S.minRefuelStops(target,tank,stations)<<endl;
    cout<<S1.minCount(target,tank,stations)<<endl;
    
    
    return 0;
}
