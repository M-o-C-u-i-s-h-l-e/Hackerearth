//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000001

vector<int> bit(MAX);

int query(int idx) {
    int res = 0;
    for (; idx; idx -= (idx & -idx))
        res += bit[idx];
    return res;
}

void update(int idx) {
    for (; idx < MAX; idx += (idx & -idx))
        bit[idx]++;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    long n, k, ans = 0;
    cin >> n >> k;
    vector<long> v(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<long> srtd(v.begin(), v.end());
    sort(srtd.begin(), srtd.end());
    for (int i = 0; i < n; i++)
        v[i] = lower_bound(srtd.begin(), srtd.end(), v[i]) - srtd.begin() + 1;
    for (int i = n-1, j = 0; i >= 0; i--, j++) {
        val[i] = j - query(v[i]);
        update(v[i]);
    }
    sort(val.begin(), val.end());
    for (int i = 0; i < n; i++)
        ans += (i - (lower_bound(val.begin(), val.begin() + i, k - val[i]) - val.begin()));
    cout << ans << endl;
}
