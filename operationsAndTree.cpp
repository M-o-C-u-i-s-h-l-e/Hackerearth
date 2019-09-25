//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100001

int n, q, ts, v[MAX], stamp[MAX], ste[MAX];
vector<int> adj[MAX];

void dfs(int pos, int par) {
	ts++;
	stamp[pos] = ts;
	for (int i : adj[pos])
		if (i != par)
			dfs(i, pos);
	ste[pos] = ts;
}

struct node {
	long l, r, lazy, sum;
};

struct segTree {
	node tree[MAX << 2];
	
	void pushUp(long k) {
		tree[k].sum = tree[k << 1].sum + tree[(k << 1) + 1].sum;
	}
	
	void pushDown(long k) {
		if (tree[k].lazy) {
			tree[k << 1].sum += (tree[k << 1].r - tree[k << 1].l + 1) * tree[k].lazy;
			tree[(k << 1) + 1].sum += (tree[(k << 1) + 1].r - tree[(k << 1) + 1].l + 1) * tree[k].lazy;
			tree[k << 1].lazy += tree[k].lazy;
			tree[(k << 1) + 1].lazy += tree[k].lazy;
			tree[k].lazy = 0;
		}
	}
	
	void build(long l, long r, long k) {
		tree[k].l = l, tree[k].r = r, tree[k].lazy = 0;
		if (l == r) {
			tree[k].sum = 0;
			return;
		}
		long mid = (l + r) >> 1;
		build(l, mid, k << 1);
		build(mid + 1, r, (k << 1) + 1);
		pushUp(k);
	}
	
	void update(long l, long r, long val, long k) {
		if (l <= tree[k].l && r >= tree[k].r) {
			tree[k].sum += (tree[k].r - tree[k].l + 1) * val;
			tree[k].lazy += val;
			return;
		}
		pushDown(k);
		long mid = (tree[k].l + tree[k].r) >> 1;
		if (l <= mid)
			update(l, r, val, k << 1);
		if (r > mid)
			update(l, r, val, (k << 1) + 1);
		pushUp(k);
	}
	
	long query(long l, long r, long k) {
		if (l <= tree[k].l && r >= tree[k].r)
			return tree[k].sum;
		pushDown(k);
		long mid = (tree[k].l + tree[k].r) >> 1;
		long ans = 0;
		if (l <= mid)
			ans += query(l, r, k << 1);
		if (r > mid)
			ans += query(l, r, (k << 1) + 1);
		return ans;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for (int i = 0; i < n; i++)
		cin >> v[i];
	dfs(0, -1);
    segTree temp, old;
	old.build(1, n, 1);
	temp.build(1, n, 1);
	for (int i = 0; i < n; i++)
		old.update(stamp[i], stamp[i], v[i], 1);
	cin >> q;
	set<int> bl;
	while (q--) {
		int ty, a, b;
		cin >> ty;
		if (ty == 1) {
			cin >> a >> b;
			a--;
			temp.update(stamp[a], ste[a], b, 1);
		} else if (ty == 2) {
			cin >> a >> b;
			a--;
			temp.update(stamp[a], stamp[a], b, 1);
		} else if (ty == 3) {
			cin >> a;
			a--;
			if (bl.count(a)) {
				temp.update(stamp[a], stamp[a], -temp.query(stamp[a], stamp[a], 1), 1);
				bl.erase(a);
			} else {
				old.update(stamp[a], stamp[a], temp.query(stamp[a], stamp[a], 1), 1);
				temp.update(stamp[a], stamp[a], -temp.query(stamp[a], stamp[a], 1), 1);
				bl.insert(a);
			}
		} else {
			cin >> a;
			a--;
			if (bl.count(a)) {
				temp.update(stamp[a], stamp[a], -temp.query(stamp[a], stamp[a], 1), 1);
			} else {
				old.update(stamp[a], stamp[a], temp.query(stamp[a], stamp[a], 1), 1);
				temp.update(stamp[a], stamp[a], -temp.query(stamp[a], stamp[a], 1), 1);
			}
			cout << old.query(stamp[a], stamp[a], 1) << endl;
		}
	}
}
