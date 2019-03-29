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

int N, tree[400100], K[100010], A[100010], Q;
int lazy[400010];

void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

int binsearch(int l, int target) {
    int r = N;
    while (l<r) {
        int mid = (l+r)/2;
        if (queryRange(1, 1, N, mid, mid) < target) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    return l;
}


int main() {
    cin >> N;
    for (int i = 1; i<=N; i++) {
        cin >> A[i];
        updateRange(1, 1, N+1, i, i, A[i]);
    }
    for (int i = 1; i<N; i++) cin >> K[i];
    cin >> Q;
    for (int i = 0; i<Q; i++) {
        char type;
        cin >> type;
        int a, b;
        cin >> a >> b;
        if (type == 's') {
            cout << queryRange(1, 1, N+1, a, b) << endl;
        } else {
            int ind = binsearch(a, A[i]+K[i]+b);
            updateRange(1, 1, N+1, a, ind, A[i]+K[i]+b);
        }
    }
    return 0;
}