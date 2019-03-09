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

int powers[110];
vector<int> schools[110];
int ppschool[110];
int N, M, K;
int chosen[110];

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i<N; i++) {
        cin >> powers[i];
    }
    for (int i = 0; i<N; i++) {
        cin >> ppschool[i];
        schools[ppschool[i]].push_back(powers[i]);
    }
    for (int i = 1; i<=M; i++) {
        sort(schools[i].begin(), schools[i].end(), greater<int>());
    }
    int newschools = 0;
    for (int i = 0; i<K; i++) {
        int ind;
        cin >> ind;
        ind--;
        if (schools[ppschool[ind]][0] > powers[ind]) {
            newschools++;
        }
    }
    cout << newschools << endl;
    return 0;
}