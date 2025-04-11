/*
g++ -std=c++17 -o bin/out a.cpp && ./bin/out
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
        string word; cin >> word;

        if (word.size() <= 10){
            cout << word << endl;
            continue;
        }

        cout << word[0] << word.size() - 2 << word[word.size() - 1] << endl;
    }
}