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

int N,K;
int tabs[110];

int main() {
    cin >> N >> K;
    for (int i = 1; i<=N; i++) {
        cin >> tabs[i];
    }
    int best = -1;
    for (int i = 1; i<=K; i++) {
        int st = 0;
        int sm = 0;
        for (int j = 1; j<=N; j++) {
            if (!((j-i)>=0 && (j-i)%K == 0)) {
                if (tabs[j] == 1) {
                    st++;
                } else {
                    sm++;
                }
            }
        }
        best = max(best, abs(st-sm));
    }
    cout << best << endl;
}