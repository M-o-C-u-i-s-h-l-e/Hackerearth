#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second

void update(vector<long> &BITree, long pos, long val, long n) {
	while (pos <= n) {
		BITree[pos] += val;
		pos += (pos & -pos);
	}
}

long query(vector<long> &BITree, long pos) {
	long sum = 0;
	while (pos) {
		sum += BITree[pos];
		pos -= (pos & -pos);
	}
	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long n, q;
	cin >> n >> q;
	vector<long> v(n+1), temp(n+1);
	for (long i = 1; i <= n; i++) {
		cin >> v[i];
		temp[i] = v[i];
	}
	sort(v.begin()+1, v.end());
	map<long, long> mp;
	for (long i = 1, idx = 1; i <= n; i++)
		if (!mp.count(v[i]))
			mp[v[i]] = idx++;
	for (long i = 1; i <= n; i++)
		v[i] = mp[temp[i]];
	vector<pair<long, pair<long, long>>> Q(q);
	for (long i = 0; i < q; i++) {
		cin >> Q[i].S.F >> Q[i].S.S;
		Q[i].F = i;
	}
	long blockSz = ceil(sqrt(n));
	sort(Q.begin(), Q.end(), [&](pair<long, pair<long, long>> a, pair<long, pair<long, long>> b){
		long t1 = a.S.F / blockSz;
		long t2 = b.S.F / blockSz;
		if (t1 != t2)
			return t1 < t2;
		return a.S.S < b.S.S;
	});
	vector<long> BITree(n+1, 0), ans(q);
	long st = 1, end = 0, val = 0;
	for (long i = 0; i < q; i++) {
		while (st < Q[i].S.F) {
			val -= query(BITree, v[st] - 1);
			update(BITree, v[st], -1, n);
			st++;
		}
		while (st > Q[i].S.F) {
			st--;
			val += query(BITree, v[st] - 1);
			update(BITree, v[st], 1, n);
		}
		while (end < Q[i].S.S) {
			end++;
			val += query(BITree, n) - query(BITree, v[end]);
			update(BITree, v[end], 1, n);
		}
		while (end > Q[i].S.S) {
			val -= query(BITree, n) - query(BITree, v[end]);
			update(BITree, v[end], -1, n);
			end--;
		}
		ans[Q[i].F] = val;
	}
	for (long i = 0; i < q; i++)
		cout << ans[i] << endl;
}
