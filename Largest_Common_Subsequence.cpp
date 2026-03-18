#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    // Step 1: Create DP table
    vector<vector<int>> dp;

    // Clear dp (optional here but used as per requirement)
    dp.clear();

    // Resize dp to (n+1) x (m+1)
    dp.resize(n + 1, vector<int>(m + 1, 0));

    // Step 2: Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Step 3: Result
    return dp[n][m];
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    int ans = longestCommonSubsequence(s1, s2);
    cout << "LCS Length: " << ans << endl;

    return 0;
}