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

long long N;

int main() {
    cin >> N;
    string str;
    cin >> str;
    char fc = str[0], lc = str[N-1];
    long long j = 1;
    while (j<N && str[j] == fc) {
        j++;
    }
    long long k = 0;
    while (k<N && str[N-k-1] == lc) {
        k++;
    }
    if (j == N) {
        cout << (N*(N+1)/2)%998244353 << endl;
        return 0;
    }
    if (fc == lc) {
        long long ans = (j+1)*(k+1);
        if (j+k == N) {
            ans--;
        }
        cout << ans%998244353 << endl;
    } else {
        cout << (j+k+1)%998244353 << endl;
    }
    return 0;
}