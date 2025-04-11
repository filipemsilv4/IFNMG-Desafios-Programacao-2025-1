/*
g++ -Wall -Werror -std=c++17 -o bin/out h.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    lli n, k, x; cin >> n >> k >> x;

    lli ans = k * x;

    for (int i = 1, tmp; i <= n; i++){
        cin >> tmp;

        if (i <= n - k) ans += tmp;
    }

    cout << ans << endl;
}