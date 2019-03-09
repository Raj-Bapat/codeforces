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

pair<int, int> divs[1010];
int currk = 0;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i<=sqrt(n); i++) {
        if (n%i == 0) {
            divs[currk] = {i, n/i};
            currk++;
        }
    }
    int best = 1000000*1010;
    for (int i = 0; i<currk; i++) {
        if (divs[i].second<k) {
            best = min(best, divs[i].first*k+divs[i].second);
        }
        if (divs[i].first<k) {
            best = min(best, divs[i].second*k+divs[i].first);
        }
    }
    cout << best << endl;
    return 0;
}