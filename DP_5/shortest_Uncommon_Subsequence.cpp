
#include <iostream>
using namespace std;

int solveRec(string &s, string &t, int i, int j) {
    // If s is finished, no uncommon subsequence possible
    if (i == s.size()) return 1e9;

    // If t is finished, any one character from s is uncommon
    if (j == t.size()) return 1;

    // Find s[i] in t starting from index j
    int k;
    for (k = j; k < t.size(); k++) {
        if (t[k] == s[i]) break;
    }

    // If s[i] is not found in t, then s[i] itself is uncommon
    if (k == t.size()) return 1;

    // Option 1: skip s[i]
    int skip = solveRec(s, t, i + 1, j);

    // Option 2: take s[i]
    int take = 1 + solveRec(s, t, i + 1, k + 1);

    return min(skip, take);
}

int shortestUncommonSubsequenceRec(string s, string t) {
    int ans = solveRec(s, t, 0, 0);

    if (ans >= 1e9) return -1;
    return ans;
}

int main() {
    string s;
    getline( cin , s);
    string t;
    getline( cin , t);
    cout<<shortestUncommonSubsequenceRec(s , t)<<endl;
    return 0;
}