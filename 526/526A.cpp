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
int arr[110];

int main() {
    cin >> N;
    for (int i = 1; i<=N; i++) {
        cin >> arr[i];
    }
    int best = 1000000000;
    for (int i = 1; i<=N; i++) {
        int tot = 0;
        for (int j = 1; j<=N; j++) {
            tot+=arr[j]*2*(abs(i-j)+j+i-2);
        }
        best = min(best, tot);
    }
    cout << best << endl;
    return 0;
}