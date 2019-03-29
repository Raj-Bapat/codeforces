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
pair<int, int> chapters[100010];

int main() {
    cin >> N;
    for (int i = 0; i<N; i++) cin >> chapters[i].first >> chapters[i].second;
    cin >> K;
    int nryet = N;
    for (int i = 0; i<N; i++) {
        if (K>chapters[i].second) {
            nryet--;
        }
    }
    cout << nryet << endl;
    return 0;
}