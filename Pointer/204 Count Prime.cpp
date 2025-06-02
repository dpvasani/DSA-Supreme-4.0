class Solution {
    public:
        int countPrimes(int n) {
            if(n==0) return 0;

            vector<bool> isPrime(n, true);
            isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

            int ans = 0;
            for (int i = 2; i < n; i++) {
                if (isPrime[i]) {
                    ans++;
                    // Mark all multiples of i as non-prime
                    int j = i * 2;
                    while (j < n) {
                        isPrime[j] = false;
                        j+=i;
                    }
                }
            }
            return ans;        
        }
    };