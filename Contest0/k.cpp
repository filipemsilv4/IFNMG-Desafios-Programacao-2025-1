/*
g++ -Wall -Werror -std=c++17 -o bin/out k.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    lli k;
    cin >> k;
    while (k--){
        lli n; cin >> n;
        vector<lli> a(n);

        for (lli i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());

        lli ans = 1;

        for (lli i = 0; i < (lli)a.size(); i++){
            lli candidate = min(i+1, a[i]);
            if (candidate > ans){
                ans = candidate;   
            }
        }

        // cout << "---------> ";
        cout << ans << endl;
    }
}