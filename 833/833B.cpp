#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <assert.h>
#include <limits>
#include <cstdio>
using namespace std;

int t[2][150010];
int dp[60][35010];
int N, K;
int cakes[36010];

int findmax(int ind, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INFINITY; // check negative numbers
    if (l == tl && r == tr) {
        return t[ind][v];
    }
    int tm = (tl + tr) / 2;
    return max(findmax(ind, v*2, tl, tm, l, min(r, tm)) ,findmax(ind, v*2+1, tm+1, tr, max(l, tm+1), r));
}


void updatemax(int ind, int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[ind][v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            updatemax(ind, v*2, tl, tm, pos, new_val);
        else
            updatemax(ind, v*2+1, tm+1, tr, pos, new_val);
        t[ind][v] = max(t[ind][v*2], t[ind][v*2+1]);
    }
}


int main() {
    cin >> N >> K;
    for (int i = 0; i<N; i++) {
        cin >> cakes[i];
    }
    for (int i = 1; i<=K; i++) {
        for (int j = i-1; j<N; j++) {
            int lower =
        }
    }
    return 0;
}