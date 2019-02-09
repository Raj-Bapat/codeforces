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

//#define RDEBUG 1
#ifdef RDEBUG
#define D(x) x
#else
#define D(x)
#endif
#define inf 0x7fffffff
#define MOD 1000000007


int N;
int occ[30];
unordered_set<char> finished;
unordered_set<char> complement;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int ii = 1;
    int speechshocks = 0;
    int totshocks = 0;
    for (; ii<N; ii++) {
        string inp;
        getline(cin, inp);
        if (inp[0] == '!') {
            speechshocks++;
            totshocks++;
            unordered_set<char> unq;
            for (int i = 2; i<inp.size(); i++) {
                unq.insert(inp[i]);
            }
            for (auto i: unq) {
                occ[(i-'a')]++;
            }
        } else if (inp[0] == '.') {
            unordered_set<char> unq;
            for (int i = 2; i<inp.size(); i++) {
                unq.insert(inp[i]);
            }
            for (auto i: unq) {
                complement.insert(i);
            }
        } else {
            totshocks++;
            occ[(inp[2]-'a')] = numeric_limits<int>::min();
            finished.insert(inp[2]);
        }
        for (int i = 0; i<26; i++) {
            char tchar = (i+'a');
            if (complement.find(tchar) != complement.end()) {
                occ[(i+'a')] = numeric_limits<int>::min();
                finished.insert(tchar);
            } else if (occ[i] < speechshocks) {
                finished.insert(tchar);
            }
        }
        if (finished.size() == 25) {
            break;
        }
    }
    cout << totshocks << endl;
    return 0;
}


