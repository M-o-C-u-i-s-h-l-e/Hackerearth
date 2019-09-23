//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100001
 
vector<long> v(MAX);
vector<int> segTree(4 * MAX);
 
int merge(int l, int m, int r, int pos) {
    int Count = 0;
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







// Another Solution
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100001
 
class node {
public:
    int ans, l, r, L, R;
};
 
vector<long> arr(MAX);
vector<node> segTree(4 * MAX);
 
node calc(node u, node v) {
    node res;
    bool mid = arr[u.r] < arr[v.l];
    res.L = u.L, res.R = v.R;
    if (u.L == u.r - u.l + 1 && mid)
        res.L += v.L;
    if (v.L == v.r - v.l + 1 && mid)
        res.R += u.R;
    res.l = u.l, res.r = v.r;
    res.ans = max({u.ans, v.ans, res.L, res.R});
    if (mid)
        res.ans = max(res.ans, u.R + v.L);
    return res;
}
 
void build(int pos, int l, int r) {
    if (l == r) {
        segTree[pos] = {1, l, r, 1, 1};
        return;
    }
    int m = (l + r) >> 1;
    build((pos << 1), l, m);
    build((pos << 1) + 1, m+1, r);
    segTree[pos] = calc(segTree[(pos << 1)], segTree[(pos << 1) + 1]);
}
 
void update(int pos, int l, int r, int x) {
    if (x < l || r < x)
        return;
    if (l == r) {
        segTree[pos] = {1, l, r, 1, 1};
        return;
    }
    int m = (l + r) >> 1;
    update((pos << 1), l, m, x);
    update((pos << 1) + 1, m+1, r, x);
    segTree[pos] = calc(segTree[(pos << 1)], segTree[(pos << 1) + 1]);
}
 
node query(int pos, int l, int r, int u, int v) {
    if (u <= l && r <= v)
        return segTree[pos];
    int m = (l + r) >> 1;
    if (m < u)
        return query((pos << 1) + 1, m+1, r, u, v);
    if (v < m + 1)
        return query((pos << 1), l, m, u, v);
    return calc(query((pos << 1), l, m, u, v), query((pos << 1) + 1, m+1, r, u, v));
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
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        build(1, 1, n);
        while (q--) {
            cin >> ty >> a >> b;
            if (ty == 1) {
                arr[a] += b;
                update(1, 1, n, a);
            } else {
                node res = query(1, 1, n, a, b);
                cout << res.ans << endl;
            }
        }
    }
}
