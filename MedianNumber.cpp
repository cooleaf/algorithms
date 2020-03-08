#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int k = (m + n) / 2;
        int i = m / 2;
        int j = k - i;

        int l1, r1, l2, r2;
        
        while (i <= m && i >= 0)
        {
            cout << "i = " << i << ", j = " << j << endl;
            l1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            r1 = (i == m ? INT_MAX : nums1[i]);
            l2 = (j == 0 ? INT_MIN : nums2[j - 1]);
            r2 = (j == n ? INT_MAX : nums2[j]);
            cout << "l1 = " << l1 << ", r1 == " << r1 << endl; 
            cout << "l2 = " << l2 << ", r2 == " << r2 << endl; 
            if ( l1 <= r2 && l2 <= r1) {
                cout << "found" << endl;
                break;
            }
            if (l1 > r2) {
                i--;
                j++;
                continue;
            }
            if (l2 > r1) {
                j--;
                i++;
                continue;
            }
        }
        // l1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        // r1 = (i == m ? INT_MAX : nums1[i]);
        // l2 = nums2[j - 1];
        // l2 = nums2[j];

        cout << "final result: " << endl;
        cout << "l1 = " << l1 << ", r1 == " << r1 << endl; 
        cout << "l2 = " << l2 << ", r2 == " << r2 << endl; 

        if ((m+n) % 2 == 1) {
            return min(r1, r2);
        }
        else {
            return static_cast<double>(max(l1, l2) + min(r1, r2))/2.0f;
        }
        
    }
};

int main() {
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    Solution s;
    cout << INT_MAX << endl;
    cout <<  setiosflags(ios::fixed) << setprecision(3) <<  s.findMedianSortedArrays(v1, v2) << endl;
}