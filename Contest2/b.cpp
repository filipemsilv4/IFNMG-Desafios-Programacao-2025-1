/*
g++ -Wall -Werror -std=c++17 -o bin/out b.cpp && ./bin/out
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

vector<int> depth;
vector<int> manager_of;

int calculate_depth(int i){
    if (depth[i] != 0) return depth[i];
    if (manager_of[i] == -1) return depth[i] = 1;
    depth[i] = 1 + calculate_depth(manager_of[i]);
    return depth[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    depth.resize(n+1);
    manager_of.resize(n+1);

    for (int i = 1; i <= n; i++){
        cin >> manager_of[i];
    }

    int max_depth = 0;

    for (int i = 1; i <= n; i++){
        max_depth = max(max_depth, calculate_depth(i));
    }

    cout << max_depth << endl;
}