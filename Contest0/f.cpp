/*
g++ -Wall -Werror -std=c++17 -o bin/out f.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    lli t;
    cin >> t;
    while (t--){
        vector<lli> t(3);
        cin >> t[0] >> t[1] >> t[2];

        sort(t.begin(), t.end());

        // if there's 2 equal values, try to cut the third in half
        if (t[0] == t[1]){
            if (t[2] % 2 == 0){
                cout << "YES" << endl;
                continue;
            }
        } else if (t[1] == t[2]){
            if (t[0] % 2 == 0){
                cout << "YES" << endl;
                continue;
            }
        }

        // corta menor.tamanho do maior e vê se bate com o segundo maior
        if (t[2] - t[0] == t[1]){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
}