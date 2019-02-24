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


vector<pair<long long, long long>> adj[300010];
long long sp[300010];
long long N,M,K;
long long edges[300010][3];
bool ein[300010];
vector<pair<long long, long long>> tree[300010];
long long postorder[300010];

void dijkstra(long long s) {
    sp[s] = 0;
    using pii = pair<long long, pair<long long, long long>>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, {s, -100}});
    while (!q.empty()) {
        long long v = q.top().second.first;
        long long d_v = q.top().first;
        long long ev = q.top().second.second;
        q.pop();
        if (d_v != sp[v]) {
            continue;
        }
        tree[edges[ev][0]].push_back({edges[ev][1], ev});
        tree[edges[ev][1]].push_back({edges[ev][0], ev});
        ein[v] = true;
        for (auto edge : adj[v]) {
            long long to = edge.first;
            long long len = edges[edge.second][2];
            if (sp[v] + len < sp[to]) {
                sp[to] = sp[v] + len;
                q.push({sp[to], {to, edge.second}});
            }
        }
    }
}

long long currk = 0;


void dfs(long long u, long long p) {
    if (tree[u].size() == 1 && tree[u][0].first == p) {
        postorder[currk] = u;
        currk++;
        return;
    }
    for (long long i = 0; i<tree[u].size(); i++) {
        long long v = tree[u][i].first;
        if (v != p) {
            dfs(v, u);
        }
    }
    postorder[currk] = u;
    currk++;
}


int main() {
    cin >> N >> M >> K;
    for (long long i = 0; i<=N; i++) sp[i] = numeric_limits<long long>::max();
    for (long long i = 0; i<M; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        edges[i][0] = a;
        edges[i][1] = b;
        edges[i][2] = c;
    }
    dijkstra(1);
    dfs(1, 0);
    long long curredges = N-1;
    long long l = 0;
    while (curredges>K) {
        ein[postorder[l]] = false;
        curredges--;
        l++;
    }
    cout << curredges << endl;
    unordered_set<int> said;
    for (int i = 1; i<=N; i++) {
        if (!ein[i]) {
            continue;
        }
        for (auto v: tree[i]) {
            if (ein[v.first] && said.find(v.second+1) == said.end()) {
                cout << v.second+1 << " ";
                said.insert(v.second+1);
            }
        }
    }
    cout << endl;
    return 0;
}