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

long long a[200010];
long long N;

int main() {
    cin >> N;
    for (long long i = 0; i<N; i++) cin >> a[i];
    long long lastmax = a[N-1];
    long long tot = lastmax;
    for (long long i = N-2; i>=0; i--) {
        long long orig = lastmax;
        lastmax = min(lastmax, a[i]);
        lastmax = lastmax == orig ? lastmax-1 : lastmax;
        lastmax = lastmax < 0 ? 0 : lastmax;
        tot+=lastmax;
    }
    cout << tot << endl;
    return 0;
}