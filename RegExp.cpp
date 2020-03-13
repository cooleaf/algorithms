#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		size_t numRow = s.length() + 1;
		size_t numCol = p.length() + 1;
		vector< vector<int> > dp(numRow, vector<int>(numCol) );
        // vector < vector<int> > dp;
		dp[0][0] = true; 
		for (size_t j = 1; j < numCol; j++) {
			if (p[j - 1] == '*') {
				if (j > 1 ) { //s = "" p= "a*"  s ="", p =".*a*
					dp[0][j] = dp[0][j - 2];
					continue;
				}
			}
			dp[0][j] = false;
		}
		for (size_t i = 1; i < numRow; i++) {
			for (size_t j = 1; j < numCol; j++) {
				if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*') { 
					if (j == 1){
						dp[i][j] = false;
					}
					if ((p[j - 2] == '.' || p[j-2] == s[i -1])) { //s = abb p = ab*  s= abb p =a.*
						dp[i][j] = dp[i][j-1] || dp[i-1][j];
					}
					dp[i][j] |= dp[i][j - 2];
					
				}
			}
		}
		return dp[numRow-1][numCol-1];
        
    }
};

int main() {
    Solution s;
    cout << s.isMatch("aaa", "a*") << endl;
    cout << s.isMatch("aaa", "a**.") << endl;
    return 0;
}