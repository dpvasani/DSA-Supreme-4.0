class Solution {
public:
    void printEvenNumbers(int n) {
        for (int i = 2; i <= n; i += 2) {
            cout << i;
            if (i != n && i + 2 <= n) cout << " ";
        }
    }
};