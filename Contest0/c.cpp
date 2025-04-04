#include <iostream>

using namespace std;

int main(){
    int x; cin >> x;
    x -= 2;

    if (x <= 0 || x % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}