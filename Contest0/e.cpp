/*
g++ -Wall -Werror -std=c++17 -o bin/out e.cpp && ./bin/out
*/

#include <bits/stdc++.h>
#include <unordered_set>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

#define MAXN 1500

using namespace std;

int main(){
    vector<lli> ans;
    ans.push_back(1);

    lli ptr2, ptr3, ptr5;
    ptr2 = ptr3 = ptr5 = 0;
    lli next2, next3, next5, tmp;

    while (ans.size() <= MAXN){
        next2 = ans[ptr2] * 2;
        next3 = ans[ptr3] * 3;
        next5 = ans[ptr5] * 5;

        tmp = min(min(next2, next3), next5);
        ans.push_back(tmp);

        if (next2 == tmp) ptr2++;
        if (next3 == tmp) ptr3++;
        if (next5 == tmp) ptr5++;
    }

    cout << "The 1500'th ugly number is " << ans[1499] << "." << endl;
}