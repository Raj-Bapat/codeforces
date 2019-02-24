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


char arr[1010][1010];
int vis[2010];
int postorder[1000100];
int N, M;
int currk = 0;
int ans[2010];

void dfs(int u) {
    vis[u] = 1;
    if (u >= N) {
        for (int i = 0; i<N; i++) {
            if (!vis[i] && arr[i][u] != '>') {
                vis[i] = 1;
                dfs(i);
            } else if (vis[i] == 1 && arr[i][u] != '>') {
                cout << "NO" << endl;
                exit(0);
            }
        }
    } else {
        for (int i = 0; i<M; i++) {
            if (!vis[i+N] && arr[u][i] != '>') {
                vis[i+N] = 1;
                dfs(i+N);
            } else if (vis[i+N] == 1 && arr[u][i] != '>') {
                cout << "NO" << endl;
                exit(0);
            }
        }
    }
    postorder[currk] = u;
    currk++;
    vis[u] = 2;
}


int main() {
    cin >> N >> M;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i<N+M; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    ans[postorder[currk-1]] = 1;
    for (int i = currk-2; i>=0; i++) {
        cout << postorder[currk-1] << endl;
    }
    return 0;
}