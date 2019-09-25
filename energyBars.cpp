//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    vector<pair<long, long>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    vector<long> ans;
    for (int i = 0, pos; i < n; i++) {
        pos = lower_bound(ans.begin(), ans.end(), v[i].second) - ans.begin();
        if (pos == ans.size())
            ans.emplace_back(v[i].second);
        else
            ans[pos] = v[i].second;
    }
    cout << ans.size() << endl;
}
