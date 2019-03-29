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
    int N, K;
    cin >> N >> K;
    if (K == N || K == 1) {
        cout << min(K-1, N-K)+N-1 + 2*N + 1 << endl;
        return 0;
    }
    cout << min(K-1, N-K)+N-1 + 2*N + 1 << endl;
    return 0;
}