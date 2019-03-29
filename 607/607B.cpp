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

int N;
int colors[510];
int dp[510][510];

int f(int i, int j, int spaces) {
//    for (int i = 0; i<spaces; i++ ) {
//        cout << " ";
//    }
//    cout << i << " " << j << endl;
    if (i == j) {
        return 1;
    }
    if (i>j) {
        return 0;
    }
    if (dp[i][j] != 1000) {
//        for (int k = 0; k<spaces; k++) {
//            cout << " ";
//        }
//        cout << i << " " << j << " " << dp[i][j] << endl;
        return dp[i][j];
    }
    dp[i][j] = 1000;
    dp[i][j] = 1+f(i+1, j, spaces+1);
    for (int k = i+2; k<=j; k++) {
        if (colors[k] == colors[i]) {
            dp[i][j] = min(dp[i][j], f(i + 1, k - 1, spaces + 1) + f(k + 1, j, spaces + 1));
        }
    }
    if (colors[i] == colors[i+1]) {
        dp[i][j] = min(dp[i][j], 1+f(i+2, j, spaces+1));
    }
//    for (int k = 0; k<spaces; k++) {
//        cout << " ";
//    }
//    cout << i << " " << j << " " << dp[i][j] << endl;
    return dp[i][j];
}

int main() {
    for (int i = 0; i<510; i++) {
        for (int j = 0; j<510; j++) {
            dp[i][j] = 1000;
        }
    }
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> colors[i];
    }
    cout << endl;
    cout << f(0, N-1, 0) << endl;
    return 0;
}