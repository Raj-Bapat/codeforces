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
    int w, h, rw1, rh1, rw2, rh2;
    cin >> w >> h >> rw1 >> rh1 >> rw2 >> rh2;
    int currw = w;
    for (; h>=0; h--) {
        currw+=h;
        if (rh1 == h) {
            currw-=rw1;
            if (currw<0) {
                w = 0;
            }
        }
        if (rh2 == h) {
            currw-=rw2;
            if (currw<0) {
                currw = 0;
            }
        }
    }
    cout << currw << endl;
}