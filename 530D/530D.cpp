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
vector<long long> adjlist[100010];
long long si[100010];
long long ai[100010];
long long postorder[100010];
long long parent[100010];
long long currk = 0;


void dfs(long long u, long long p) {
    if (adjlist[u].size() == 1 && adjlist[u][0] == p) {
        postorder[currk] = u;
        currk++;
        return;
    }
    for (long long i = 0; i<adjlist[u].size(); i++) {
        long long v = adjlist[u][i];
        if (v != p) {
            parent[v] = u;
            dfs(v, u);
        }
    }
    postorder[currk] = u;
    currk++;
}

int main() {
    cin >> N;
    for (long long i = 2; i<=N; i++) {
        long long a;
        cin >> a;
        adjlist[a].push_back(i);
        adjlist[i].push_back(a);
    }
    for (long long i = 1; i<=N; i++) {
        cin >> si[i];
    }
    parent[1] = 0;
    dfs(1, 0);
    long long tot = 0;
    for (long long i = 0; i<currk; i++) {
        long long node = postorder[i];
        if (si[node] == -1) {
            si[node] = numeric_limits<long long>::max();
            for (long long j = 0; j<adjlist[node].size(); j++) {
                long long v = adjlist[node][j];
                if (v != parent[node]) {
                    si[node] = min(si[node], si[v]);
                }
            }
            for (long long j = 0; j<adjlist[node].size(); j++) {
                long long v = adjlist[node][j];
                if (v != parent[node]) {
                    tot+=si[v]-si[node];
                }
            }
            if (si[node] < si[parent[node]]) {
                cout << -1 << endl;
                return 0;
            }
            if (si[node] == numeric_limits<long long>::max()) {
                si[node] = si[parent[node]];
            }
        } else {
            long long node = postorder[i];
            for (long long j = 0; j<adjlist[node].size(); j++) {
                long long v = adjlist[node][j];
                if (v != parent[node]) {
                    tot+=si[v]-si[node];
                }
            }
        }
    }
    cout << tot+si[1] << endl;
    return 0;
}