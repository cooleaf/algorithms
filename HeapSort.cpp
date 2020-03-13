#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int>& MaxHeapify(vector<int>& heap, int i) {
         int len = heap.size();
         return MaxHeapify(heap, i, len);
    }
    vector<int>& MaxHeapify(vector<int>& heap, int i, int len) {
        int l = left(i);
        int r = right(i);
        int root = i ;
        while ( l <= len || r <= len) {
            cout << "root = " << root << ", left = " << l << ", right = " << r << endl;
            int largest = root;
            if (l <= len && heap[largest] < heap[l]) {
                largest = l;
            }
            if(r <= len && heap[largest] < heap[r]) {
                largest = r;
            }
            if(largest == root) {
                break;
            }
            else {
                int t = heap[root];
                heap[root] = heap[largest];
                heap[largest] = t;
                root = largest;
                l = left(root);
                r = right(root);
            }
        }
        return heap;
    }
    vector<int>& BuildMaxHeap(vector<int>& heap) {
        int len = heap.size();
        for (int i = len / 2; i >= 0; i--) {
            MaxHeapify(heap, i);
        }
        return heap;
    }

    vector<int>& HeapSort(vector<int>& v) {
        vector<int>& h = BuildMaxHeap(v);
        int nSize = h.size() - 1;
        int t = 0;
        for (int i = nSize; i >= 1; i--) {
            cout << "Round " << i << endl;
            PrintContainer(h);
            t = h[0];
            h[0] = h[i];
            h[i] = t;
            MaxHeapify(h, 0, --nSize);
        }
        return h;
    } 

    int HeapMaximum(vector<int> v) {
        return v[0];
    }

    int HeapExtractMax(vector<int> v, int& err) {
        err = 0;
        if (v.size() < 1) {
            err = -1;
        }
        int max = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();
        MaxHeapify(v, 0);
        return max;
    }

    bool HeapIncreaseKey(vector<int> v, int i, int key) {
        if (i >= v.size() ) {
            return false;
        }
        if (v[i] >= key) {
            return false;
        }
        v[i] = key;
        int p = root(i);
        while (i > 0 && v[p] < v[i]){
            int t = v[p];
            v[p] = v[i];
            v[i] = t;
            i = p;
            p = root(i);
        }
        return true;
    }

    bool MaxHeapInsert(vector<int> v, int key) {
        v.push_back(INT_MIN);
        return HeapIncreaseKey(v, v.size() - 1, key);
    }

    template <class T>
    void PrintContainer(T& v){
        cout << "[";
        for (auto& n : v )
        {
            cout << n << ", " ; 
        }
        cout <<"]" << endl;
    }
private:
    int left(int root) {
        return (root << 1) + 1;
    }
    int right(int root) {
        return (root << 1) + 2;
    }
    int root(int leaf) {
        return (leaf - 1) >> 1;
    }
};

int main() {
    vector<int> v = {1,7,8, 5,6,5,6,2,3,4,2,4,3,2};
    Solution s;
    s.MaxHeapify(v, 0);
    s.PrintContainer< vector<int> >(v);
    int err = 0;
    return 0;
}