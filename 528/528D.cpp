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

vector<int> adjlist[100010];
int N;
double S;
vector<int> levels[100010];
int maxd = -1;

void dfs(int u, int p, int d) {
    levels[d].push_back(u);
    maxd = max(maxd, d);
    if (adjlist[u].size() == 1 && adjlist[u][0] == p) {
        return;
    }
    for (auto v: adjlist[u]) {
        if (v != p) {
            dfs(v, u , d+1);
        }
    }
}

int main() {
    cin >> N >> S;
    for (int i = 0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(1, 0, 1);
    double numnodes = 0;
    double best = pow(10, 9)+1;
    double secondbest = 1;
    for (int i = 2; i<=maxd; i++) {
        for (auto v:levels[i]) {
            numnodes++;
            double edgeper = S/numnodes;
            if (best>edgeper*(secondbest+i-2)) {
                best = edgeper*(secondbest+i-2);
            }
            if (levels[i].size()>1) {
                secondbest = i;
            }
        }
    }
    cout << best << endl;
    return 0;
}