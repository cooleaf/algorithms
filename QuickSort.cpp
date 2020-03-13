#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> IntArray;

class Solution {
public:
    int Partition(IntArray& A, int p, int r){
        int x = A[r];
        int i = p - 1;
        int t = 0;
        for (int j = p; j < r; j++) {
            if (A[j] <= x) {
                i++;
                t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
            
        }
        A[r] = A[i + 1];
        A[i + 1] = x;
        return i + 1;
    }

    int QuickSort(IntArray& A, int p, int r) {
        if (p >= r)  // only 1 elements 
        {
            return 0;
        }
        else if(p + 1 == r) {

        }
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
        
        return 0;
    }

};

int main() {
    IntArray v = {1,8, 4, 6, 2, 7, 11, 4, 5};
    // IntArray v = {10,8};
    Solution s;
    s.QuickSort(v, 0, v.size() - 1);
    return 0;
}