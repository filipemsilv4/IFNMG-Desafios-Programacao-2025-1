/*
g++ -std=c++17 -o bin/out a.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

#define MAXN 1'000'000'000

using namespace std;

int main(){
    // Precompute primes
    lli lim = sqrt(MAXN);
    vector<bool> mark(lim + 1, false);
    vector<lli> primes;

    for (lli i = 2; i <= lim; i++){
        if(mark[i]) continue; // non prime

        primes.emplace_back(i);
        for (lli j = i * i; j <= lim; j += i){
            mark[j] = true;
        }
    }

    lli t;
    cin >> t;
    while (t--){
        lli n, m; cin >> n >> m;

        vector<bool> isPrime(m - n + 1, true);
        for (auto i : primes){
            for (lli j = max(i * i, (n + i - 1) / i * i); j <= m; j += i){
                isPrime[j - n] = false;
            }
        }
        if (n == 1) isPrime[0] = false;

        for (lli i = 0; i < isPrime.size(); i++){
            if (isPrime[i]) cout << i + n << endl;
        }

        cout << endl;
    }
}