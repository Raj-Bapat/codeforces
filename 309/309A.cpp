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

#define MOD 1000000007
#define MAXN 1000001
#define ll long long

ll K, c[1010];
ll pref[1010];
ll dp[1010];
ll factorial[1000100];


ll gcdExtended(ll a, ll b, ll &x, ll &y)
{
    // Base Case
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}

ll inverse(ll a) {
    ll x, y;
    ll g = gcdExtended(a, MOD, x, y);
    if (g != 1) {
        assert(0);
    } else {
        x = (x % MOD + MOD) % MOD;
        return x;
    }
}

long long binomial_coefficient(ll n, ll k) {
    return factorial[n] * inverse(factorial[k]) % MOD * inverse(factorial[n - k]) % MOD;
}

ll f(ll i) {
    if (i == -1) {
        return 1;
    }
    if (dp[i] != numeric_limits<ll>::max()) {
        return dp[i]%MOD;
    }
    dp[i] = ((binomial_coefficient(pref[i]-1, c[i]-1)%MOD) * (f(i-1)%MOD))%MOD;
//    cout << (binomial_coefficient(pref[i]-1, c[i]-1)%MOD) << " " << (f(i-1)%MOD) << endl;
//    cout << i << " " << dp[i] << endl;
    return dp[i]%MOD;
}


int main() {
    cin >> K;
    for (ll i = 0; i<K; i++) {
        cin >> c[i];
    }
    for (int i = 0; i<1010; i++) {
        dp[i] = numeric_limits<ll>::max();
    }
    pref[0] = c[0];
    for (ll i = 1; i<K; i++) {
        pref[i] = c[i]+pref[i-1];
    }
    factorial[0] = 1;
    for (ll i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    cout << f(K-1)%MOD << endl;
    return 0;
}