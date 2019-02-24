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
    int n, arr[110];
    cin >> n;
    for (int i = 0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    vector<int> v;
    for (int i = 0; i<n; i+=2) {
        if (i+1<n) {
            v.push_back(arr[i+1]);
        }
        cout << arr[i] << " ";
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i<v.size()-1; i++) {
        cout << v[i] << " ";
    }
    cout << v[v.size()-1] << endl;
    return 0;
}