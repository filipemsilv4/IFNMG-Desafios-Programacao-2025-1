/*
g++ -Wall -Werror -std=c++17 -o bin/out f.cpp && ./bin/out
*/

// CodeForces - 1033A

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
     * The first line contains a single integer n (3 ≤ n ≤ 1000) 
     * — the dimensions of the chessboard.
     */

    int n;
    cin >> n;

    /*
     * The second line contains two integers ax and ay (1 ≤ ax, ay ≤ n) 
     * — the coordinates of Alice's queen.
     */

    int ax, ay;
    cin >> ax >> ay;

    /*
     * The third line contains two integers bx and by (1 ≤ bx, by ≤ n) 
     * — the coordinates of Bob's king.
     */

    int bx, by;
    cin >> bx >> by;

    /*
     * The fourth line contains two integers cx and cy (1 ≤ cx, cy ≤ n) 
     * — the coordinates of the location that Bob wants to get to.
     */

    int cx, cy;
    cin >> cx >> cy;

    /*
     * It is guaranteed that:
     * 1. Bob's king is currently not in check
     * 2. The target location is not in check
     * 3. The king is not on the same square as the queen (ax ≠ bx or ay ≠ by)
     * 4. The target location is not:
     *    - The queen's position (cx ≠ ax or cy ≠ ay)
     *    - The king's position (cx ≠ bx or cy ≠ by)
     */

    // so the king cant cross ax or ay
    // verify if ax is between bx and cx, if so, then the king can't move to cx
    if ((ax > bx && ax < cx) || (ax < bx && ax > cx)) {
        cout << "NO" << endl;
        return 0;
    }

    // verify if ay is between by and cy, if so, then the king can't move to cy
    if ((ay > by && ay < cy) || (ay < by && ay > cy)) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;

}