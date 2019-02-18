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

int main() {
    cin >> N;
    for (int i = 0; i<N; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 1) {
            cout << 1 << " " << 2 << endl;
            continue;
        }
        if (r%2 == 0) {
            cout << r/2 << " " << r << endl;
        } else {
            r--;
            cout << r/2 << " " << r << endl;
        }
    }
}