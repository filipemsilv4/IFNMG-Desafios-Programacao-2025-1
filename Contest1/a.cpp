/*
g++ -Wall -Werror -std=c++17 -o bin/out a.cpp && ./bin/out
*/

#include <bits/stdc++.h>
#include <unordered_map>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    string og = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    unordered_map<char, char> mp;

    for (int i = 0; i < (int)og.size(); i++){
        mp[og[i]] = og[i-1];
    }

    string input;
    while (getline(cin, input)){
        for (char c : input){
            if (mp.find(c) != mp.end()) cout << mp[c];
            else cout << c;
        }
        cout << endl;
    }

}