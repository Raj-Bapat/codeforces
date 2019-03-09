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

int ax, ay, bx, by, cx, cy;
int bdist = 1000000, cdist = 1000000;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int mindists[1010][1010];
int visited[1010][1010];
int maxx = -1 , maxy = -1;
pair<int, int> parent[1010][1010];

bool inBounds(int x, int y) {
    if (x>=0 && y>=0 && x<=maxx && y<=maxy) {
        return 1;
    } else {
        return 0;
    }
}
int arr[3][2];

int main() {
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<2; j++) {
            cin >> arr[i][j];
        }
        maxx = max(maxx, arr[i][0]);
        maxy = max(maxy, arr[i][1]);
    }
    for (int i = 0; i<3; i++) {
        queue<int> q;
        q.push(arr[i][0]);
        q.push(arr[i][1]);
        q.push(1);
        while (!q.empty()) {
            int ux = q.front();
            q.pop();
            int uy = q.front();
            q.pop();
            int d = q.front();
            q.pop();
            visited[ux][uy] = true;
            mindists[ux][uy]+=d-1;
            for (int j = 0; j<4; j++) {
                int vx = ux+dx[j];
                int vy = uy+dy[j];
                if (inBounds(vx, vy) && !visited[vx][vy]) {
                    visited[vx][vy] = true;
                    q.push(vx);
                    q.push(vy);
                    q.push(d+1);
                }
            }
        }
        memset(visited, 0, sizeof(visited));
    }
    int best = numeric_limits<int>::max();
    int fx = -1, fy = -1;
    for (int i = 0; i<=maxx; i++) {
        for (int j = 0; j<=maxy; j++) {
            best = min(best, mindists[i][j]+1);
            if (mindists[i][j]+1 == best) {
                fx = i;
                fy = j;
            }
        }
    }
    queue<int> q;
    q.push(fx);
    q.push(fy);
    q.push(1);
    while (!q.empty()) {
        int ux = q.front();
        q.pop();
        int uy = q.front();
        q.pop();
        int d = q.front();
        q.pop();
        visited[ux][uy] = true;
        mindists[ux][uy]+=d-1;
        for (int j = 0; j<4; j++) {
            int vx = ux+dx[j];
            int vy = uy+dy[j];
            if (inBounds(vx, vy) && !visited[vx][vy]) {
                visited[vx][vy] = true;
                q.push(vx);
                q.push(vy);
                q.push(d+1);
                parent[vx][vy] = make_pair(ux, uy);
            }
        }
    }
    cout << best << endl;
    for (int i = 0; i<3; i++) {
        pair<int, int> currpt = {arr[i][0], arr[i][1]};
        while (!(currpt.first == fx && currpt.second == fy)) {
            cout << currpt.first << " " << currpt.second << endl;
            currpt = parent[currpt.first][currpt.second];
        }
    }
    cout << fx << " " << fy << endl;
    return 0;
}