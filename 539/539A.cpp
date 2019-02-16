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
    int n, v;
    cin >> n >> v;
    if (v>=n) {
        cout << n-1 << endl;
        return 0;
    }
    int sum = v;
    for (int i = 2; i<=n-v; i++) {
        sum+=i;
    }
    cout << sum << endl;
    return 0;
}