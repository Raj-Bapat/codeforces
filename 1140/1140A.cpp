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
    int N;
    cin >> N;
    int stopat = -1;
    int days = 0;
    for (int i = 0; i<N; i++) {
        int a;
        cin >> a;
        stopat = max(stopat, a);
        if (stopat <= i+1) {
            days++;
            stopat = -1;
        }
    }
    cout << days << endl;
    return 0;
}