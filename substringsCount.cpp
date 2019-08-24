#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n;
	unordered_map<string, vector<int>> mp;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			for (int k = 1; k <= str.size()-j; k++)
				mp[str.substr(j, k)].emplace_back(i + 1);
	}
	for (auto itr = mp.begin(); itr != mp.end(); itr++)
		itr->second.erase(unique(itr->second.begin(), itr->second.end()), itr->second.end());
	cin >> q;
	while (q--) {
		int l, r, val = 0;
		cin >> l >> r >> str;
		if (mp.count(str)) {
			int st = lower_bound(mp[str].begin(), mp[str].end(), l) - mp[str].begin();
			int end = upper_bound(mp[str].begin(), mp[str].end(), r) - mp[str].begin();
			val = end - st;
		}
		cout << val << endl;
	}
}
