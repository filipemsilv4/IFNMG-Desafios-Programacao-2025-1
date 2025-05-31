/*
g++ -Wall -Werror -std=c++17 -o bin/out c.cpp && ./bin/out
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

#define MAX_N 110

string input = "";

// dp[pos][current_match_length] will store the number of "QAQ" subsequences
// starting from input_str[pos] given that 'current_match_length' characters
// of "QAQ" have already been matched prior to pos.
// current_match_length:
// 0: Looking for the first 'Q'
// 1: Found 'Q', looking for 'A'
// 2: Found "QA", looking for the second 'Q'
int dp[MAX_N][3];
bool jc[MAX_N][3]; // memoization check

// target_pattern helps identify which character we are looking for
char target_pattern[] = {'Q', 'A', 'Q'};

int solve(int pos, int current_match_length){
    // base case: QAQ formed
    if (current_match_length == 3) return 1;

    // base case: end of string
    if (pos >= (int)input.size()) return 0;

    // memoization check
    if (jc[pos][current_match_length]) return dp[pos][current_match_length];
    jc[pos][current_match_length] = true;

    // recursive case:
    // 1. pick the current character
    // 2. not pick the current character
    int pick = 0, not_pick = 0;
    if (input[pos] == target_pattern[current_match_length]) pick = solve(pos + 1, current_match_length + 1);
    not_pick = solve(pos + 1, current_match_length);

    return dp[pos][current_match_length] = pick + not_pick;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    memset(jc, false, sizeof(jc));
    cout << solve(0, 0) << endl;

    // // debug
    // cout << "Q   QA  QAQ" << endl;
    // for (int i = 0; i < 5; i++){
    //     for (int j = 0; j < 3; j++){
    //         cout << dp[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
}