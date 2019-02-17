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

#define MOD 1000000007

string str;
long long suffprod[100010];

int main() {
    cin >> str;
    suffprod[str.length()] = 1;
    long long numas = 0;
    for (long long i = str.length()-1; i>=0; i--) {
        if (str[i] == 'a') {
            numas++;
            suffprod[i] = suffprod[i+1]%MOD;
        } else if (str[i] == 'b') {
            suffprod[i] = ((numas+1)*suffprod[i+1])%MOD;
            numas = 0;
        } else {
            suffprod[i] = suffprod[i+1]%MOD;
        }
    }
    long long ans = 0;
    for (int i = 0; i<str.length(); i++) {
        if (str[i] == 'a') {
            ans = (ans+suffprod[i])%MOD;
        }
    }
    cout << ans%MOD << endl;
}