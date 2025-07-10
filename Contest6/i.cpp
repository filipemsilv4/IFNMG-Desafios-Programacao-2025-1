/*
g++ -Wall -Werror -std=c++17 -o bin/out i.cpp && ./bin/out
*/

#include <iostream>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli t;

    while (cin >> t){
        lli ans = 0;
        for (lli i = 0, tmp; i < 5; i++){
            cin >> tmp;
            if (tmp == t) ans++;
        }

        cout << ans << "\n";
    }

}