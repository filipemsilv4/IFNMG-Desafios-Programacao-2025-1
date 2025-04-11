/*
g++ -Wall -Werror -std=c++17 -o bin/out b.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

#define MAXN 10'000

using namespace std;

int main(){
    map<lli,lli> dp;
    map<lli,bool> jc;

    lli l, r;
    while (cin >> l >> r){
        lli ans = 0;

        bool swapped = false;
        if (r < l){
            swap(l, r);
            swapped = true;
        }
        
        for (int i = l; i <= r; i++){
            lli n = i;
            lli sum = 0;
            while (n != 1){
                if (jc[n]){
                    sum += dp[n];
                    break;
                }
    
                if (n % 2 == 1) n = 3 * n + 1;
                else n = n / 2;
    
                sum++;
            }
    
            jc[i] = true;
            dp[i] = sum;
    
            ans = max(ans, dp[i] + 1);
        }

        if (swapped) swap(l, r);

        
        cout << l << " " << r << " " << ans << endl;

    }
}