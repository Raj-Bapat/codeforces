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

long long N;
vector<pair<long long, long long>> adjlist[300010];
long long nw[300010];
long long saved[300010];

long long f(long long u, long long last) {
    if (adjlist[u].size() == 1 && adjlist[u][0].first == last) {
        saved[u] = nw[u];
        return nw[u];
    }
    long long best = 0, nextbest = 0;
    for (long long i = 0; i<adjlist[u].size(); i++) {
        long long v = adjlist[u][i].first;
        if (v == last) continue;
        long long case1 = f(v, u)-adjlist[u][i].second;
        if (case1>best) {
            nextbest = best;
            best = case1;
        } else if (case1>nextbest) {
            nextbest = case1;
        }
    }
    saved[u] = max(best+nextbest+nw[u], nw[u]);
    return max(best+nw[u], nw[u]);
}



int main() {
    cin >> N;
    for (long long i = 1; i<=N; i++) {
        cin >> nw[i];
    }
    for (long long i = 0; i<N-1; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }
    f(1, 0);
    long long best = 0;
    for (long long i = 1; i<=N; i++) {
        best = max(best, saved[i]);
    }
    cout << best << endl;
    return 0;
}