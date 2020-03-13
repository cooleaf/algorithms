#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		size_t len = str.length();
		int ans = 0;
		int neg = INT_MIN / 10;
		int negR = INT16_MIN % 10;
		int pos = INT_MAX / 10;
		int posR = INT16_MAX % 10;
		int nSign = 0;
		size_t i = 0;
		for (; i < len; i++) { //find first char is sign or number
			if (str[i] == 0x20) { //find space
				continue;
			}
			if (str[i] == '+' || str[i] == '-') { //find sign
				nSign = str[i] == '+' ? 1 : -1;
				i++;
				break;
			}
			if (str[i] >= '0' && str[i] <= '9'){ //find number
				nSign = 1;
				break;
			}
			return 0;
		}
		for (; i < len; i++)
		{
			char c = str[i];
			if (c >= '0' && c <= '9')
			{
				int n = (c - '0') * nSign;
                
				if (nSign == -1){
					if (ans < neg || ((ans == neg) && (n < negR))) {
						return INT_MIN;
					}
				}
				else{
					if (ans > pos || ((ans == pos) && (n > posR))) {
						return INT_MAX;
					}
				}
				ans = ans * 10 + n;

				continue;
			}
			break;
		}
		return ans;
    }
    bool isPalindrome(int x) {
        int ans = 0;
        int backup = x;
        while (x > 0) {
            int reminder = x % 10;
            if (ans > INT_MAX/10 || ((ans == INT_MAX) && (reminder > INT_MAX % 10))) {
                return false;
            }
            ans = ans * 10 + reminder;
            x /= 10;
        }
        return ans == backup;
    }
};

int main(){
    Solution s;
    // s.myAtoi("-2147483648");
    cout << s.isPalindrome(121);
    return 0;

}