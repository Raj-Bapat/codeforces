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

long long N, s, v[1010];

int main() {
    cin >> N >> s;
    long long minval = numeric_limits<long long>::max();
    for (int i = 0; i<N; i++) {
        cin >> v[i];
        minval = min(minval, v[i]);
    }
    long long starttotal = 0;
    for (int i = 0; i<N; i++) {
        starttotal+=v[i]-minval;
    }
    if (starttotal+minval*N<s) {
        cout << -1 << endl;
        return 0;
    }
    s-=starttotal;
    if (s<=0) {
        cout << minval << endl;
        return 0;
    }
    cout << minval - (long long)ceil((double)s/(double)N) << endl;
    return 0;
}