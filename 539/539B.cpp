
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

long long N;
long long arr[5010];

int main() {
    cin >> N;
    for (long long i = 0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    long long tot = 0;
    for (long long i = 0; i<N; i++) {
        tot+=arr[i];
    }
    long long best = tot;
    for (long long i = 0; i<N; i++) {
        for (long long j = i+1; j<N; j++) {
            for (long long k = 1; k<=10; k++) {
                if (arr[j]%k == 0) {
                    best = min(best, tot - arr[j] + (arr[j]/k) - arr[i] + arr[i]*k);
                    best = min(best, tot - arr[j] + (arr[j]/(arr[j]/k)) - arr[i] + arr[i]*(arr[j]/k));
                }
            }
        }
    }
    cout << best << endl;
    return 0;
}