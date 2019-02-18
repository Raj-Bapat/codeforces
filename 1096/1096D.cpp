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

long long dp[100010][5];
long long N;
string str;
long long amb[100010];
string refer = "hard";

long long f(long long i, long long covered) {
    if (i == N) {
        if (covered == 4) {
            return 0;
        } else {
            return 998244353*10*10*10*10*10 + 100 + 100;
        }
    }
    if (dp[i][covered] != 998244353*10*10*10*10*10 + 100) {
        return dp[i][covered];
    }
    if (covered<4 && str[i] == refer[covered]) {
        dp[i][covered] = min(dp[i][covered], amb[i]+f(i+1, covered+1));
    }
    dp[i][covered] = min(dp[i][covered], f(i+1, covered));
    return dp[i][covered];
}

int main() {
    for (int i = 0; i<100010; i++) {
        for (int j = 0; j<5; j++) {
            dp[i][j] = 998244353*10*10*10*10*10 + 100;
        }
    }
    cin >> N;
    cin >> str;
    for (long long i = 0; i<N; i++) {
        cin >> amb[i];
    }
    cout << f(0, 0) << endl;
}