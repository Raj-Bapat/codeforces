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

int arr[100010];

int main() {
    int N;
    cin >> N;
    int maxnum = -1;
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
        maxnum = max(maxnum, arr[i]);
    }
    int best = 0;
    for (int i = 0; i<N; i++) {
        if (arr[i] != maxnum) {continue;}
        int curri = i;
        while (curri+1<N && arr[curri] == arr[curri+1]) {
            curri++;
        }
        best = max(best, curri-i+1);
        i = curri;
    }
    cout << best << endl;
    return 0;
}