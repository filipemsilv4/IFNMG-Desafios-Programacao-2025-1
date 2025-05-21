/*
g++ -Wall -Werror -std=c++17 -o bin/out c.cpp && ./bin/out
*/

#include <iostream>
#include <vector>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

vector<bool> JC;
vector<lli> dp;
vector<lli> a;

lli n;

lli solve(lli i){
    if (i > n) return 0;
    if (JC[i]) return dp[i];

    dp[i] = a[i] + solve(a[i] + i);
    JC[i] = true;

    return dp[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli t;
    cin >> t;
    while (t--){
        cin >> n;

        a.clear();
        dp.clear();
        JC.clear();
        
        a.reserve(n+1);
        dp.reserve(n+1);
        JC.reserve(n+1);
        
        a.resize(n+1);
        dp.resize(n+1, 0);
        JC.resize(n+1, false);

        for (lli i = 1; i <= n; i++) cin >> a[i];

        lli ans = 0;

        for (lli i = 1; i <= n; i++){
            ans = max(ans, solve(i));
        }

        // cout << "-----> ";
        cout << ans << "\n";

        // for (auto i : dp){
        //     cout << i << " ";
        // } cout << endl;
    }
}