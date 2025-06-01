#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -------------------- [1] Naive Prime Check --------------------
    // Time: O(N^2), Space: O(1)
    bool isPrimeNaive(int n) {
        if (n <= 1) return false;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int countPrimesNaive(int n) {
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrimeNaive(i)) count++;
        }
        return count;
    }

    // -------------------- [2] Square Root Prime Check --------------------
    // Time: O(N√N), Space: O(1)
    bool isPrimeSqrt(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int countPrimesSqrt(int n) {
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrimeSqrt(i)) count++;
        }
        return count;
    }

    // -------------------- [3] Sieve of Eratosthenes --------------------
    // Time: O(N log log N), Space: O(N)
    int countPrimesSieve(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;
            }
        }

        return count(isPrime.begin(), isPrime.end(), true);
    }

    // -------------------- [4] Segmented Sieve (for range [L, R]) --------------------
    // Time: O((R−L+1) log log √R), Space: O(R−L+1)
    vector<int> segmentedSieve(long long L, long long R) {
        long long limit = sqrt(R) + 1;

        // Step 1: Find base primes up to sqrt(R)
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> basePrimes;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) basePrimes.push_back(i);
        }

        // Step 2: Mark non-primes in [L, R]
        vector<bool> isPrimeSegment(R - L + 1, true);

        for (int prime : basePrimes) {
            long long firstMultiple = max(prime * prime, (L + prime - 1) / prime * prime);
            for (long long j = firstMultiple; j <= R; j += prime) {
                isPrimeSegment[j - L] = false;
            }
        }

        if (L == 1) isPrimeSegment[0] = false;

        // Collect primes
        vector<int> primesInRange;
        for (long long i = L; i <= R; i++) {
            if (isPrimeSegment[i - L]) primesInRange.push_back(i);
        }

        return primesInRange;
    }

    // -------------------- [5] Master Runner --------------------
    void runAllApproaches(int n) {
        cout << "🔹 Naive Approach Count     : " << countPrimesNaive(n) << "  (O(N^2))\n";
        cout << "🔹 Square Root Approach     : " << countPrimesSqrt(n) << "  (O(N√N))\n";
        cout << "🔹 Sieve of Eratosthenes    : " << countPrimesSieve(n) << "  (O(N log log N))\n";
    }

    void runSegmentedSieveDemo(long long L, long long R) {
        cout << "\n📦 Segmented Sieve Range [" << L << ", " << R << "]\n";
        vector<int> primes = segmentedSieve(L, R);
        cout << "🔹 Primes in range: ";
        for (int p : primes) cout << p << " ";
        cout << "\n🔹 Count: " << primes.size() << endl;
    }
};

// -------------------- [6] Main Function --------------------
int main() {
    Solution sol;

    int n = 30;
    sol.runAllApproaches(n);

    // Try with large values like 1e9, 1e12 for real-world segmented sieve use
    long long L = 100, R = 150;
    sol.runSegmentedSieveDemo(L, R);

    return 0;
}
