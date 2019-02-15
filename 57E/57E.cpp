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

const int N = 1e6 + 6;
int a[N], l[N], r[N];
map <int, int> m, mr;

int tree[N];

int query(int idx) {
    int ret = 0;
    while(idx > 0) {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    return ret;
}

void update(int idx) {
    while(idx < N) {
        tree[idx] += 1;
        idx += idx & -idx;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }

    int cnt = 2;
    for(auto x: m) {
        mr[x.first] = cnt++;
    }
    for(int i = 0; i < n; i++) {
        a[i] = mr[a[i]];
    }

    for(int i = 0; i < n; i++) {
        l[i] = query(N - a[i] - 1);
        update(N - a[i]);
    }

    memset(tree, 0, sizeof tree);
    for(int i = n - 1; i >= 0; i--) {
        r[i] = query(a[i] - 1);
        update(a[i]);
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += l[i] * 1LL * r[i];
    }
    cout << ans << endl;
    return 0;
}
