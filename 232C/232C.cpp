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

#define MOD 1000000007
int N, Q;
vector<int> adjlist[300010];
long long tree[2][300010];
bool visited[300010];
int level[300010];
int start[300010];
int postorder[300010];
int currk;

void update(int t, int idx, long long val) {
    while (idx<300010) {
        tree[t][idx] = (tree[t][idx] + val) % MOD;
        idx += (idx & -idx);
    }
}

long long getsum(int t, int idx) {
    long long sum = 0;
    while (idx>0) {
        sum = (sum + tree[t][idx]) % MOD;
        idx -= (idx & -idx);
    }
    return sum;
}

void dfs(int v, int l) {
    visited[v] = true;
    currk++;
    start[v] = currk;
    level[v] = l;
    for (int i = 0; i<adjlist[v].size(); i++) {
        int u = adjlist[v][i];
        if (!visited[u]) {
            dfs(u, l + 1);
        }
    }
    postorder[v] = currk;
}

int main() {
    ios_base::sync_with_stdio (false);
    cin >> N;
    for (int i = 2; i<=N; i++) {
        int a;
        cin >> a;
        adjlist[a].push_back(i);
        adjlist[i].push_back(a);
    }
    dfs(1, 1);
    cin >> Q;
    for (int i = 0; i<Q; i++) {
        int type;
        cin >> type;
        int v;
        long long x, k;
        if (type == 1) {
            cin >> v >> x >> k;
            update(0, start[v], x + 1ll * k * level[v]);
            update(0, postorder[v]+1, - (x + 1ll * k * level[v]));
            update(1, start[v], k);
            update(1, postorder[v]+1, -k);
        } else  {
            cin >> v;
            long long ans = getsum(0, start[v]) - getsum(1, start[v]) * level[v];
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
            cout << ans << endl;
        }
    }
    return 0;
}
