class Solution {
public:
    int sumNumbers(int n) {
        // do not write cin >> n, as input n is already taken in the driver code
        // Implement the loop logic to sum n numbers
        int val;
        int sum = 0;
        int i = 1;
        while (i <= n) {
            cin >> val;
            sum += val;
            i++;
        }
        return sum;
    }
};