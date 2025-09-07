class Solution {
public:
    void printNumberMultipleTimes(int num, int n) {
        for (int i = 0; i < n; ++i) {
            cout << num;
            if (i != n - 1) cout << " ";
        }
    }
};