//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, k;
vector<vector<int>> bit, ans;

int query(int pos, int idx) {
    int res = INT_MAX;
    while (idx) {
        res = min(res, bit[pos][idx]);
        idx -= (idx & -idx);
    }
    return res;
}

void update(int pos, int idx, int val) {
    while (idx <= n) {
        bit[pos][idx] = min(bit[pos][idx], val);
        idx += (idx & -idx);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> k;
    bit.resize(k+1, vector<int>(n+1, INT_MAX));
    ans.resize(k+1, vector<int>(n+1, 0));
    vector<int> v(n+1), idx(n+1);
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        m[v[i]];
    }
    int pos = 1;
    for (pair<int, int> i : m) {
        idx[pos] = i.first;
        m[i.first] = pos++;
    }
    int Max = -1;
    for (int i = 1; i <= n; i++) {
        int x = m[v[i]];
        ans[1][x] = x;
        update(1, x, x);
        for (int j = 2, res; j <= k; j++) {
            res = query(j-1, x-1);
            ans[j][x] = res;
            update(j, x, res);
        }
        if (ans[k][x] <= n)
            Max = max(Max, v[i] - idx[ans[k][x]]);
    }
    cout << Max << endl;
}
