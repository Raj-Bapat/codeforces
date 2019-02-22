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

long long arr[200010];
long long N, K, M;

int main() {
    cin >> N >> M >> K;
    long long best = 0, nextbest = 0;
    for (long long i = 0; i<N; i++) {
        cin >> arr[i];
        if (arr[i] > best) {
            nextbest = best;
            best = arr[i];
        } else if (arr[i]>nextbest) {
            nextbest = arr[i];
        }
    }
    long long divs = M/(K+1);
    long long left = M%(K+1);
    cout << K*best*divs+nextbest*divs+best*left;
    return 0;
}
