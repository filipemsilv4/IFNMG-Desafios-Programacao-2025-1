/*
g++ -Wall -Werror -std=c++17 -o bin/out d.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

string phrase = "the quick brown fox jumps over the lazy dog";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    string line;

    // reads number of test cases
    if (!(cin >> T)) return 0;
    cin.ignore();            // ignores the '\n' after the number
    getline(cin, line);      // reads the empty line

    while (T--) {
        vector<string> lines;

        // reads until finds an empty line (testcase separator)
        while (getline(cin, line)) {
            if (line.empty()) break;
            lines.push_back(line);
        }

        map<char, char> mp;
        bool found = false;

        for (auto line : lines){
            if (line.size() != phrase.size()) continue;
            
            bool ok = true;
            map<char, char> mp_local;
            map<char, char> inv_mp_local;

            // try to match line[i] with phrase[i]
            for (int i = 0; i < (int)line.size(); i++){    
                char c, p; // c for enCrypted, p for Phrase
                c = line[i]; p = phrase[i];

                // if it's a space, must continue beeing a space
                if ((p == ' ') != (c == ' ')){
                    ok = false;
                    break;
                }
                if (c == ' ') continue;

                // if never found before, map it (1 to 1 relationship)
                if (!mp_local.count(c) && !inv_mp_local.count(p)){
                    mp_local[c] = p;
                    inv_mp_local[p] = c;
                }
                // if it's already matched, they should... match!
                else if (mp_local[c] != p || inv_mp_local[p] != c){
                    ok = false;
                    break;
                }
            }
    
            if (ok && mp_local.size() == 26){
                mp = mp_local;
                found = true;
                break;
            }
        }

        if (found){
            for (auto line : lines){
                for (auto c : line){
                    if (c == ' ') cout << ' ';
                    else cout << mp[c];
                }
                cout << "\n";
            }
        } else {
            cout << "No solution.\n";
        }

        if (T) cout << "\n";
    }

    return 0;
}
