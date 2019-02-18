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

int N, K;
int arr[10];
int dp[500010];

int main() {
    cin >> N >> K;
    int maximum = -1;
    int minimum = 10;
    for (int i = 0; i<K; i++) {
        cin >> arr[i];
        maximum = max(maximum, arr[i]);
        minimum = min(minimum, arr[i]);
    }
    int minval = minimum*(N/2);
    int maxval = maximum*(N/2);
    dp[minval] = 1;
    for (int i = minval+1; i<=maxval; i++) {
        for (int j = 0; j<K; j++) {
            if (i-arr[j]>=0) {
                dp[i]=(dp[i]+dp[i-arr[j]])%998244353;
            }
        }
    }
    int tot = 0;
    for (int i = minval; i<=maxval; i++) {
        tot = (tot+(dp[i]*dp[i])%998244353)%998244353;
    }
    cout << tot << endl;
}