/*
g++ -Wall -Werror -std=c++17 -o bin/out e.cpp && ./bin/out
*/

#include <iostream>
#include <vector>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
     * The first line of the input contains the only integer n (1 ≤ n ≤ 1000) 
     * — the number of the naughty students.
     */

    int n;
    cin >> n;

    /*
     * The second line contains n integers p₁, ..., pₙ (1 ≤ pᵢ ≤ n), 
     * where pᵢ indicates the student who was reported to the teacher by student i.
     */

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    /*
     * For each student a from 1 to n, determine which student would receive
     * two holes in their badge if student a was the first one caught by the teacher.
     */

    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1, false);
        int current = i;

        while (!visited[current]) {
            visited[current] = true;
            current = p[current];
        }

        cout << current << " ";
    }

    cout << "\n";

    return 0;
}