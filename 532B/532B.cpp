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

int N, M;
vector<int> adj[100010];
int maxsz = 100000000;
bool ans[100010];

int main() {
    cin >> N >> M;
    for (int i = 1; i<=M; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
    for (int i = 1; i<=N; i++) {
        maxsz = min(maxsz, (int)adj[i].size());
    }
    for (int j = 0; j<maxsz; j++) {
        int maxind = -1;
        for (int i = 1; i<=N; i++) {
            maxind = max(maxind, adj[i][j]);
        }
        ans[maxind] = true;
    }
    for (int i = 1; i<=M; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}