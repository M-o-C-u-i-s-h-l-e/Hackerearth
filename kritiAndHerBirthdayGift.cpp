#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> q;
	vector<pair<pair<int, int>, pair<int, string>>> Q(q);
	for (int i = 0; i < q; i++) {
		cin >> Q[i].F.F >> Q[i].F.S >> Q[i].S.S;
		Q[i].S.F = i;
	}
	int blockSz = ceil(sqrt(n));
	sort(Q.begin(), Q.end(), [&](pair<pair<int, int>, pair<int, string>> a, pair<pair<int, int>, pair<int, string>> b){
		int t1 = a.F.F / blockSz;
		int t2 = b.F.F / blockSz;
		if (t1 ^ t2)
			return t1 < t2;
		return a.F.S < b.F.S;
	});
	vector<int> ans(q);
	unordered_map<string, int> mp;
	int st = 0, end = -1;
	for (int i = 0; i < q; i++) {
		Q[i].F.F--, Q[i].F.S--;
		while (st < Q[i].F.F)
			mp[v[st++]]--;
		while (st > Q[i].F.F)
			mp[v[--st]]++;
		while (end < Q[i].F.S)
			mp[v[++end]]++;
		while (end > Q[i].F.S)
			mp[v[end--]]--;
		ans[Q[i].S.F] = (mp.count(Q[i].S.S)) ? mp[Q[i].S.S] : 0;
	}
	for (int i : ans)
		cout << i << endl;
}







// Another Solution
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n;
	unordered_map<string, vector<int>> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		m[str].emplace_back(i + 1);
	}
	cin >> q;
	while (q--) {
		int l, r, val = 0;
		cin >> l >> r >> str;
		if (m.count(str)) {
			int st = upper_bound(m[str].begin(), m[str].end(), l-1) - m[str].begin();
			int end = upper_bound(m[str].begin(), m[str].end(), r) - m[str].begin();
			val = end - st;
		}
		cout << val << endl;
	}
}
