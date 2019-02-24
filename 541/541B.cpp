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


int main() {
    long long n;
    pair<long long, long long> arr[10010];
    cin >> n;
    arr[0] = {0,0};
    for (long long i = 1; i<=n; i++) {
        long long a, b;
        cin >> a >> b;
        if (a == arr[i-1].first && b == arr[i-1].second) {
            n--;
            i--;
        } else {
            arr[i].first = a;
            arr[i].second = b;
        }
    }
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    long long tot = 1;
    for (long long i = 0; i<n; i++) {
        long long lb = 0, hb = 0;
        if (arr[i].first>arr[i].second) {
            lb = arr[i].first;
        } else {
            lb = arr[i].second;
        }
        if (arr[i+1].first>arr[i+1].second) {
            hb = arr[i+1].second;
        } else {
            hb = arr[i+1].first;
        }
        tot+= hb-lb+1>0 ? hb-lb+1 : 0;
        if (arr[i].first == arr[i].second) {
            tot--;
        }
    }
    cout << tot << endl;
}