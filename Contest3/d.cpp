/*
g++ -Wall -Werror -std=c++17 -o bin/out d.cpp && ./bin/out
*/

#include <vector>
#include <climits>
#include <iostream>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

#define MAXN 110

vector<vector<lli>> dp(MAXN, vector<lli>(MAXN, INT_MAX));

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][1] = 0;

    // Standing at cell (x, y)
    // Move right to cell (x, y+1) — costs x burles
    // Move down to cell (x+1, y) — costs y burles

    for (lli i = 1; i < MAXN; i++){
        for (lli j = 1; j < MAXN; j++){
            if (i == 1 && j == 1) continue;
            dp[i][j] = min(dp[i-1][j] + j, dp[i][j-1] + i);
        }
    }

    lli t;
    cin >> t;
    while (t--){
        lli n, m, k; cin >> n >> m >> k;

        // (1, 1) -> (n, m) spending k burles
        if (dp[n][m] == k){
            cout << "YES" << endl;
        } else {
            // cout << "NO (" << dp[n][m] << ")" << endl;
            cout << "NO" << endl;
        }
    }
}