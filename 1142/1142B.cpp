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
    long long N;
    cin >> N;
    string str = to_string(N);
    long long maxtot = 0;
    for (long long i = 0; i<str.length(); i++) {
        if (str[i] == '0') {
            continue;
        }
        long long tot = 1;
        for (long long j = 0; j<i; j++) {
            tot*=(stoi((str[j]+string())));
        }
        if (!(i == 0 && str[i] == '1')) {
            tot *= (stoi((str[i] + string())) - 1);
        }
        for (long long j = i+1; j<str.length(); j++) {
            tot*=9;
        }
        maxtot = max(tot, maxtot);
    }
    long long currtot = 1;
    for (long long j = 0; j<str.length(); j++) {
        currtot*=(stoi((str[j]+string())));
    }
    cout << max(maxtot, currtot) << endl;
    return 0;
}