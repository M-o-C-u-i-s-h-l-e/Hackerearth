//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100001

vector<long> v(MAX), segTree(4 * MAX);
 
int merge(int l, int m, int r, int pos) {
    long Count = 0;
    if (v[m] < v[m+1]) {
        int i = m;
        while (i < r && v[i] < v[i+1])
            Count++, i++;
        i = m + 1;
        while (i > l && v[i-1] < v[i])
            Count++, i--;
    }
    return max(segTree[(pos << 1) + 1], max(segTree[(pos << 1) + 2], Count));
}
 
void update(int l, int r, int idx, int val, int pos) {
    if (l == r) {
        v[l] += val;
        return;
    }
    int m = l + (r - l) / 2;
    if (l <= idx && idx <= m)
        update(l, m, idx, val, (pos << 1) + 1);
    else
        update(m+1, r, idx, val, (pos << 1) + 2);
    segTree[pos] = merge(l, m, r, pos);
}
 
int query(int l, int r, int qL, int qR, int pos) {
    if (r < qL || qR < l || l > r)
        return 0;
    if (qL <= l && r <= qR)
        return segTree[pos];
    int m = l + (r - l) / 2;
    int Count = 0;
    if (v[m] < v[m+1]) {
        int i = m;
        while (i < qR && qL <= i && v[i] < v[i+1])
            Count++, i++;
        i = m + 1;
        while (i > qL && i <= qR && v[i-1] < v[i])
            Count++, i--;
    }
    return max(Count, max(query(l, m, qL, qR, (pos << 1) + 1), query(m+1, r, qL, qR, (pos << 1) + 2)));
}
 
void buildSegTree(int l, int r, int pos) {
    if (l == r) {
        segTree[pos] = 1;
        return;
    }
    int m = l + (r - l) / 2;
    buildSegTree(l, m, (pos << 1) + 1);
    buildSegTree(m+1, r, (pos << 1) + 2);
    segTree[pos] = merge(l, m, r, pos);
}
 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        long n, q, ty, a, b;
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        buildSegTree(0, n-1, 0);
        while (q--) {
            cin >> ty >> a >> b;
            if (ty == 1) {
                update(0, n-1, a-1, b, 0);
            } else {
                cout << query(0, n-1, a-1, b-1, 0) << endl;
            }
        }
    }
}
