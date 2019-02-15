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

unordered_map<long long, double> pfact;
int N,B;

int getdivisor(int a) {
    if (a%2 == 0) {
        return 2;
    }
    for (int i = 3; i<ceil(sqrt((double)(a))); i+=2) {
        if (a%i == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    cin >> N >> B;

    return 0;
}