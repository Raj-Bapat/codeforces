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

long long digits[65010];
long long N;

int main() {
    cin >> N;
    for (long long i = 0; i<N; i++) {
        char a;
        cin >> a;
        string b = (a+string());
        digits[i] = stoi(b);
    }
    long long ans = 0;
    for (long long i = 0; i<N; i++) {
        if (digits[i]%2 == 0) {
            ans+=i+1;
        }
    }
    cout << ans << endl;
    return 0;
}