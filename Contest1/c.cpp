/*
g++ -Wall -Werror -std=c++17 -o bin/out c.cpp && ./bin/out
*/

#include <bits/stdc++.h>
#include <unordered_map>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    
    string a;
    string b;
    while (getline(cin, a) && getline(cin, b)){
        vector<pair<lli,lli> > mp(26);
        for (char c : a){
            mp[c - 'a'].first++;
        }

        for (char c : b){
            mp[c - 'a'].second++;
        }
        

        // cout << "-----> ";
        for (int i = 0; i < (int)mp.size(); i++){
            for (int j = 0; j < min(mp[i].first, mp[i].second); j++){
                cout << (char)(i + (int)'a');
            }
        }

        cout << endl;
    }

}