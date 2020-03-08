#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    string findLongestString(string s, int l, int r) {
        while (l >= 0 && r < s.length())
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
                continue;
            }
            else
            {
                break;
            }
            
        }
        return s.substr(l+1, r - l - 1);
    }
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        string ans = s.substr(0, 1);
        int max = 1;
        for (size_t i = 0; i < s.length() - 1; i++)
        {
            string s1 = findLongestString(s, i, i);
            string s2 = findLongestString(s, i, i + 1);
            if (s1.length() > max)
            {
                max = s1.length();
                ans = s1;
            }
            if (s2.length() > max)
            {
                max = s2.length();
                ans = s2;
            }   
        }
        return ans;
    }


};

int main() {
    Solution s;
    cout << s.longestPalindrome("bb") << endl; 
    cout << s.longestPalindrome("abbcd") << endl;
}

