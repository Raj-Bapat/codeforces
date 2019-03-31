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

vector<int> adj[100010];
bool respect[100010];
vector<int> ans;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        if (a != -1) {
            adj[a].push_back(i+1);
        }
        respect[i+1] = (bool)b;
    }
    for (int i = 1; i<=N; i++) {
        int alld = respect[i];
        for (auto v:adj[i]) {
            alld *= respect[v];
        }
        if (alld) {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i<ans.size()-1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;

    return 0;
}