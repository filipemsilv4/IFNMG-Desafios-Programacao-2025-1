/*
g++ -Wall -Werror -std=c++17 -o bin/out e.cpp && ./bin/out < input.txt
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int run = 0;

    while (true){
        int n; cin >> n;
        if (n == 0) break;
        ++run;

        // Consume the newline character left by cin >> n
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string std_sol = "";
        string tmp;
        for (int i = 0; i < n; i++){
            getline(cin, tmp); // Read the whole line
            if (i > 0) std_sol += "\n";
            std_sol += tmp;
        }

        int m;
        cin >> m;
        
        // Consume the newline character left by cin >> m
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string team_out = "";
        for (int i = 0; i < m; i++){
            getline(cin, tmp); // Read the whole line
            if (i > 0) team_out += "\n";
            team_out += tmp;
        }

        cout << "Run #" << run << ": ";

        if (team_out == std_sol){
            cout << "Accepted\n";
            continue;
        }

        string std_nums = "";
        string team_nums = "";

        for (char c : std_sol) if (isdigit(c)) std_nums += c;

        for (char c : team_out) if (isdigit(c)) team_nums += c;

        if (std_nums == team_nums){
            cout << "Presentation Error\n";
            continue;
        }

        cout << "Wrong Answer\n";
    }

    return 0;
}