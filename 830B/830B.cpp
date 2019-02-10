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

//#define RDEBUG 1
#ifdef RDEBUG
#define D(x) x
#else
#define D(x)
#endif
#define inf 0x7fffffff
#define MOD 1000000007


int tree[100010];
int N;
void add(int i, int c) {
    while (i<=N+10) {
        tree[i]+=c;
        i+=i&-i;
    }
}
int sum(int i) {
    int s = 0;
    while (i>0) {
        s+=tree[i];
        i-=i&-i;
    }
    return s;
}
vector<int> value[100010];

int main() {
    cin >> N;
    for (int i = 1; i<=N; i++) {
        int a;
        cin >> a;
        add(i, 1);
        value[a].push_back(i);
    }
    int p = 1;
    long long int ans = 0;
    for (int i = 1; i<100010; i++) {
        if (value[i].size() == 0) continue;
        auto it = lower_bound(value[i].begin(), value[i].end(), p);
        auto rec = it;
        if (it != value[i].end()) {
            while (it != value[i].end()) {
                ans+=sum(*it)-sum(p-1);
                p = *it;
                add(*it, -1);
                it++;
            }

        }
        it = value[i].begin();
        if (it != rec) {
            ans+=sum(N+1)-sum(p-1);
            p = 1;
            while (it != rec) {
                ans += sum(*it)-sum(p-1);
                p = *it;
                add(*it, -1);
                it++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}