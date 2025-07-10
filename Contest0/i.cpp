/*
g++ -Wall -Werror -std=c++17 -o bin/out i.cpp && ./bin/out
*/

#include <iostream>
#include <vector>

using namespace std;

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

vector<lli> p;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli t;
    cin >> t;
    while (t--){
        lli n; cin >> n;
        
        p.clear();
        p.resize(n);

        for (lli i = 0; i < n; i++) cin >> p[i];
        
        bool found = false;
        for (lli j = 1; j < n - 1; j++){
            bool found_i = false, found_k = false;

            lli i, k;
            for (i = j - 1; i >= 0; i--){
                if (p[i] < p[j]){
                    found_i = true;
                    break;
                }
            }

            for (k = j + 1; k < n; k++){
                if (p[k] < p[j]){
                    found_k = true;
                    break;
                }
            }

            if (found_i && found_k){
                cout << "YES\n";
                cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                found = true;
                break;
            }
        }

        if (found) continue;

        cout << "NO\n";

        // cout << "------------\n";
    }
}