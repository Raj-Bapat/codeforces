#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<set<int>> g;

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    vector<int> num(n);
    for (int i = 0; i<n; i++) {
        int cur;
        cin >> cur;
        num[cur-1] = i;
    }
    vector<int> sueta;
    for (int i = 0; i<m; i++) {
        int v, u;
        cin >> v >> u;
        g[num[u-1]].insert(num[v-1]);
    }
    set<int> cur = g[n-1];
    int ans = 0;
    for (int i = n-2; i>=0; i--) {
        auto it = cur.find(i);
        if (it != cur.end())
            ans++;
        else {
            std::vector<int> s3;
            set_intersection(cur.begin(), cur.end(), g[i].begin(), g[i].end(), std::back_inserter(s3));
            cur.clear();
            for (auto x : s3)
                cur.insert(x);
        }
    }
    cout << ans << endl;
    return 0;
}