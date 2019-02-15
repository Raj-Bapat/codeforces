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
    int sq = floor(sqrt((double)N));
    if (sq*sq>=N) {
        cout << 2*sq << endl;
    } else if (sq*(sq+1)>=N) {
        cout << 2*sq+1 << endl;
    } else {
        cout << 2*sq+2 << endl;
    }
    return 0;
}