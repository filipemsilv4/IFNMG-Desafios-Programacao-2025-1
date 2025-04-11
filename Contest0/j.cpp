/*
g++ -Wall -Werror -std=c++17 -o bin/out j.cpp && ./bin/out
*/

#include <bits/stdc++.h>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    lli t;
    cin >> t;
    while (t--){
        lli w, d, h;
        cin >> w >> d >> h;

        pair<lli, lli> l; // laptop
        pair<lli, lli> p; // projector

        cin >> l.first >> l.second;
        cin >> p.first >> p.second;

        vector<pair<lli,lli> > cand_edge(4); // coords
        vector<lli> dist_og_to_edge(4); // distance from og point to edge

        cand_edge[0] = {0, p.second};
        cand_edge[1] = {w, p.second};
        cand_edge[2] = {p.first, 0};
        cand_edge[3] = {p.first, d};

        dist_og_to_edge[0] = abs(p.first - 0);
        dist_og_to_edge[1] = abs(p.first - w);
        dist_og_to_edge[2] = abs(p.second - 0);
        dist_og_to_edge[3] = abs(p.second - d);

        vector<lli> dists(4, h);
        lli ans = LLONG_MAX;

        for (lli i = 0; i < 4; i++){
            dists[i] += dist_og_to_edge[i];

            // Manhattan distance
            dists[i] += (abs(cand_edge[i].first - l.first) + abs(cand_edge[i].second - l.second));
            if (dists[i] < ans){ 
                ans = dists[i];
                // cout << "i: " << i << endl;
                // cout << "dist_to_edge: " << dist_og_to_edge[i] << endl;
                // cout << "cand_edge: " << cand_edge[i].first << " " << cand_edge[i].second << endl;
                // cout << "----" << endl;
            }
        }

        // cout << "-----> ";
        cout << ans << endl;
    }
}