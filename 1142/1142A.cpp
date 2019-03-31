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
int arr[200010];

int main() {
    cin >> N;
    int last1 = -1, last2 = -1;
    for (int i = 0; i<N; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            last1 = i;
        } else {
            last2 = i;
        }
    }
    cout << min(last1, last2)+1 << endl;
    return 0;
}