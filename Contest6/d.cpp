/*
g++ -Wall -Werror -std=c++17 -o bin/out d.cpp && ./bin/out
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

const vector<int> CARDS_VALUES = {10000, 1000, 100, 10, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M) {
        // Read M rounds
        int ans = 0;
        for (int round = 0; round < M; round++) {
            int B; // budget
            cin >> B;
            
            vector<int> cards(N);
            int round_sum = 0;
            for (int i = 0; i < N; i++) {
                cin >> cards[i];
                round_sum += cards[i];
            }
            
            // cards[0] is Daedalus's card (first player)
            int amount_won = 0;
            if (round_sum <= B) {
                amount_won = cards[0];
            }
            round_sum -= cards[0];

            // find max card value that Deadalus can use
            for (auto val : CARDS_VALUES){
                if (round_sum + val <= B){
                    ans += val - amount_won;
                    break;
                }
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}