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

long long N, K;
pair<long long, long long> arr[300010];
long long pref[300010];

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {return a.second>b.second;}

int main() {
    cin >> N >> K;
    for (long long i = 0; i<N; i++) cin >> arr[i].first >> arr[i].second;
    long long currsum = 0;
    sort(arr, arr+N, cmp);
    multiset<long long> currin;
    for (long long i = 0; i<N; i++) {
        if (i >= K) {
            long long best = *(currin.begin());
            currin.erase(currin.begin());
            currsum-=best;
        }
        currin.insert(arr[i].first);
        pref[i] = currsum+arr[i].first;
        currsum+=arr[i].first;
    }
    long long ans = -1;
    for (long long i = 0; i<N; i++) ans = max(ans, pref[i]*arr[i].second);
    cout << ans << endl;
    return 0;
}