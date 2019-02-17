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

long long tree[400010];
long long episodes[200010];
long long N,B;
vector<long long> seasonsper[200010];


void update(long long ind, long long num) {
    while (ind<=N) {
        tree[ind]+=num;
        ind+=(ind&-ind);
    }
}

long long getsum(long long ind) {
    long long sum = 0;
    while (ind) {
        sum+=tree[ind];
        ind-=(ind&-ind);
    }
    return sum;
}

int main() {
    cin >> N;
    for (long long i = 1; i<=N; i++) {
        cin >> episodes[i];
        if (episodes[i]<=N) {
            seasonsper[episodes[i]].push_back(i);
        }
        update(i, 1);
    }
    long long ans = 0;
    for (long long i = 1; i<=N; i++) {
        long long val = min(N, episodes[i]);
        ans+=getsum(val);
        for (long long j = 0; j<seasonsper[i].size(); j++) {
            update(seasonsper[i][j], -1);
        }
    }
    for (long long i = 1; i<=N; i++) {
        if (i<=episodes[i]) {
            ans--;
        }
    }
    cout << ans/2 << endl;
    return 0;
}