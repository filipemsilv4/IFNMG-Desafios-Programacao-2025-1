/*
g++ -Wall -Werror -std=c++17 -o bin/out b.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

// {line, column}
vector<pair<lli, lli>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
}; // Directions: Northwest, North, Northeast, West, East, Southwest, South, Southeast

lli m, n, k; 
vector<string> grid;

// checks if word s is present at position {l,c} following direction d
bool check_word(string &w, lli l, lli c, pair<lli,lli> d){
    if (w[0] != grid[l][c]) return false;

    for (lli i = 1; i < (lli) w.length(); i++){
        l += d.first;
        c += d.second;

        // check boundaries
        if (l < 0 || c < 0 || l >= m || c >= n) return false;

        // check if characters match
        if (grid[l][c] != w[i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli t;
    cin >> t;
    bool first_t = true;
    while (t--){
        if (first_t) first_t = false; else cout << "\n";

        cin >> m >> n;

        grid.assign(m, "");
        for (lli i = 0; i < m; i++){
            cin >> grid[i];
            for (char &c : grid[i]){
                c = tolower(c);
            }
        }
        
        cin >> k;
        vector<string> words(k);
        for (lli i = 0; i < k; i++){
            cin >> words[i];
            for (char &c : words[i]){
                c = tolower(c);
            }
        }

        for (auto word : words){
            bool found = false;
            for (lli line = 0; line < m; line++){
                for (lli col = 0; col < n; col++){
                    // choose a direction
                    for (auto direct : directions){
                        if (check_word(word, line, col, direct)){
                            cout << line + 1 << " " << col + 1 << "\n";
                            found = true;
                        }
                    }
                    if (found) break;
                }
                if (found) break;
            }
        }


    }
}