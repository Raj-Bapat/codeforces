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

int N, K;
int visited[1100];
int info[1100];
int st[1100];

int main() {
    cin >> N >> K;
    set<pair<int, int>> s;
    for (int i = 0; i<K; i++) {
        int a;
        cin >> a;
        info[i] = a;
        st[i] = 0;
        s.insert({a, i});
    }
    int currt = 0;
    int interesting = 0;
    double done = 0;
    int i = K;
    while (!s.empty() || i<N) {
        currt = (*(s.begin())).first;
        int orig = (*(s.begin())).first;
        while ((*(s.begin())).first == orig) {
            s.erase(s.begin());
            done++;
        }
        if (i<N) {
            for (int k = s.size(); k<K; k++) {
                if (i>=N) {
                    break;
                }
                int a;
                cin >> a;
                st[i] = currt;
                s.insert({a+currt, i});
                i++;
            }
        }
        double perc = floor((done/N)*100 + 0.5);
        for (auto j: s) {
            int asdf = (*(s.begin())).first;
            if ((*(s.begin())).first-currt>perc-(currt-st[j.second])) {
                if (!visited[j.second]) {
                    visited[j.second]++;
                    interesting++;
                }
            }
        }
    }
    cout << interesting << endl;
    return 0;
}