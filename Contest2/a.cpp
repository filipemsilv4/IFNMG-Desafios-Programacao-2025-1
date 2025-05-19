/*
g++ -Wall -Werror -std=c++17 -o bin/out a.cpp && ./bin/out
*/

#include <iostream>
#include <vector>
#include <set>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli n; cin >> n;

    vector<lli> v(n+1);

    for (lli i = 1; i <= n; i++){
        cin >> v[i];
    }

    bool found = false;
    for (lli i : v){
        if (found){
            cout << "YES\n";
            return 0;
        }

        found = (v[v[v[i]]] == i) && (v[i] != v[v[i]] && v[i] != v[v[v[i]]] && v[v[i]] != v[v[v[i]]] );
    }

    cout << "NO\n";

    return 0;
}