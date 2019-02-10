//
// Created by r on 2019-02-09.
//

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

const long long asdf = (1<<24);

long long dp[asdf];
long long N;
pair<long long, long long> coords[25];
pair<int, int> nextaction[asdf];
long long dists[25][25];

inline long long dist(long long x1, long long y1, long long x2, long long y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

long long f(long long mask) {
    if (mask == (1<<N)-1) {
        return 0;
    }
    if (dp[mask] != numeric_limits<long long>::max()) {
        return dp[mask];
    }
    for (int i = 0; i<N; i++) {
        if ((mask & (1 << i)) == 0) {
            long long case1 = 2*dists[24][i] + f((mask | (1 << i)));
            if (case1 < dp[mask]) {
                dp[mask] = case1;
                nextaction[mask] = {24, i};
            }
            for (int j = i+1; j<N; j++) {
                if ((mask & (1 << j)) == 0) {
                    long long tmpmask = mask | (1 << i);
                    tmpmask |= (1 << j);
                    long long case2 = dists[24][i]+dists[i][j]+dists[24][j] + f(tmpmask);
                    if (case2 < dp[mask]) {
                        dp[mask] = case2;
                        nextaction[mask] = {i, j};
                    }
                }
            }
            break;
        }
    }
    return dp[mask];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> coords[24].first >> coords[24].second;
    cin >> N;
    for (long long i = 0; i<(1<<N); i++) {
        dp[i] = numeric_limits<long long>::max();
    }
    for (long long i = 0; i<N; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            dists[i][j] = dist(coords[i].first, coords[i].second, coords[j].first, coords[j].second);
        }
    }
    for (int i = 0; i<N; i++) {
        dists[i][24] = dist(coords[i].first, coords[i].second, coords[24].first, coords[24].second);
        dists[24][i] = dists[i][24];
    }
//    dp[((1<<N)-1)] = 0;
//    for (int mask = ((1<<N)-1)-1; mask>=0; mask--) {
//        for (int i = 0; i<N; i++) {
//            if ((mask & (1 << i)) == 0) {
//                long long case1 = 2*dists[24][i] + dp[(mask | (1 << i))];
//                if (case1 < dp[mask]) {
//                    dp[mask] = case1;
//                    nextaction[mask] = {24, i};
//                }
//                for (int j = i+1; j<N; j++) {
//                    if ((mask & (1 << j)) == 0) {
//                        long long tmpmask = mask | (1 << i);
//                        tmpmask |= (1 << j);
//                        long long case2 = dists[24][i]+dists[i][j]+dists[24][j] + dp[tmpmask];
//                        if (case2 < dp[mask]) {
//                            dp[mask] = case2;
//                            nextaction[mask] = {i, j};
//                        }
//                    }
//                }
//            }
//        }
//    }
    long long len = f(0);
    cout << len << endl;
    long long currmask = 0;
    while (currmask != ((1<<N)-1)) {
        cout << 0 << " ";
        if (nextaction[currmask].first == 24) {
            cout << nextaction[currmask].second+1 << " ";
            currmask |= (1 << nextaction[currmask].second);
        } else {
            cout << nextaction[currmask].first+1 << " " << nextaction[currmask].second+1 << " ";
            long long ncurrmask = currmask | (1 << nextaction[currmask].first);
            ncurrmask |= (1 << nextaction[currmask].second);
            currmask = ncurrmask;
        }
    }
    cout << 0 << endl;
    return 0;
}
//
//
