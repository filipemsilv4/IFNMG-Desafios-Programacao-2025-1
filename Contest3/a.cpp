/*
g++ -Wall -Werror -std=c++17 -o bin/out a.cpp && ./bin/out
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n + 1); // last element is a dummy element to avoid out of bounds
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++){
        int local_ans = 1;
        for (int j = i + 1; j <= n; j++){
            if (a[j] > a[j-1]) local_ans++;
            else {
                a[i] = local_ans;
                ans = max(ans, local_ans);
                i = j - 1;
                break;
            }
        }
    }

    cout << ans << endl;
}