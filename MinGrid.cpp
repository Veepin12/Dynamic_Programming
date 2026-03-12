//
//  MinGrid.cpp
//  DS_in_Cpp
//
//  Created by Veepin Chaudhary on 10/02/26.
//
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
     int minPathSum(vector<vector<int>>& grid) {
         // Top Down Approch Implementation..
        int m = grid.size();
        int n = grid[0].size();

        // First row
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }

        // First column
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        // Rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};
int main(){
    class Solution S;
    
    vector<vector<int>> grid={{1,2,3,4,5},
                              {0,0,0,0,0},
                              {1,2,3,4,4}};
    cout<<S.minPathSum(grid)<<endl;
    return 0;
}
geytoreryp  8