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

long long A[510][510], B[510][510];
long long N,M;

int main() {
    cin >> N >> M;
    for (long long i = 0; i<N; i++) {
        for (long long j = 0; j<M; j++) {
            cin >> A[i][j];
        }
    }
    for (long long i = 0; i<N; i++) {
        for (long long j = 0; j<M; j++) {
            cin >> B[i][j];
        }
    }
    for (long long k = 0; k<N; k++) {
        long long i = k;
        long long j = 0;
        unordered_map<long long, long long> m;
        while (i>=0 && j<N) {
            if (m.find(A[i][j]) == m.end()) {
                m[A[i][j]] = 0;
            }
            if (m.find(B[i][j]) == m.end()) {
                m[B[i][j]] = 0;
            }
            m[A[i][j]]++;
            m[B[i][j]]++;
            i--;
            j++;
        }
        for (auto l: m) {
            if (l.second%2 != 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    for (long long k = 0; k<N; k++) {
        long long i = N-1;
        long long j = k;
        unordered_map<long long, long long> m;
        while (i>=0 && j<N) {
            if (m.find(A[i][j]) == m.end()) {
                m[A[i][j]] = 0;
            }
            if (m.find(B[i][j]) == m.end()) {
                m[B[i][j]] = 0;
            }
            m[A[i][j]]++;
            m[B[i][j]]++;
            i--;
            j++;
        }
        for (auto l: m) {
            if (l.second%2 != 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}