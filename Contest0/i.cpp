/*
g++ -Wall -Werror -std=c++17 -o bin/out i.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli t;
    cin >> t;
    while (t--){
        lli n; cin >> n;
        vector<lli> p(n + 1);
        for (lli i = 1; i <= n; i++) cin >> p[i];


        bool found = false;
        for (lli i = 2; i < n; i++){
            if (p[i - 1] < p[i] && p[i] > p[i + 1]){
                cout << "YES\n";
                cout << i-1 << " " << i << " " << i+1 << "\n";
                found = true;
                break;
            }
        }

        if (found) continue;

        cout << "NO\n";
    }
}