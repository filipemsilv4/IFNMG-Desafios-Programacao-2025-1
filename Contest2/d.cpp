/*
g++ -Wall -Werror -std=c++17 -o bin/out d.cpp && ./bin/out
*/

#include <iostream>
#include <cmath>
#include <algorithm>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;


/*
A rook moves any number of fields horizontally or vertically.
A bishop moves any number of fields diagonally.
A king moves one field in any direction — horizontally, vertically or diagonally.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int,int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    if (start == end) {
        cout << "0 0 0" << endl;
        return 0;
    }

    int min_rook, min_bishop, min_king;

    /*
    Print three space-separated integers: the minimum number of moves the rook, the bishop and the king (in this order) is needed to move from field (r1, c1) to field (r2, c2). If a piece cannot make such a move, print a 0 instead of the corresponding number.
    */

    // rook
    min_rook = start.first == end.first || start.second == end.second ? 1 : 2;

    // bishop
    if ((start.first + start.second) % 2 != (end.first + end.second) % 2) {
        min_bishop = 0;  // different colors, impossible to reach
    } else if (abs(start.first - end.first) == abs(start.second - end.second)) {
        min_bishop = 1;  // same diagonal
    } else {
        min_bishop = 2;  // same color but not on same diagonal
    }

    // king
    min_king = max(abs(start.first - end.first), abs(start.second - end.second));

    cout << min_rook << " " << min_bishop << " " << min_king << endl;

    return 0;
}