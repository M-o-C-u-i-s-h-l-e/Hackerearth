//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int query(vector<int> &bit, int idx) {
    int ans = 0;
    while (idx) {
        ans += bit[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

void update(vector<int> &bit, int idx, int val, int n) {
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, q, ty, a, b;
    cin >> n;
    vector<int> v(n+1), odd(n+1, 0), even(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        (v[i] & 1) ? update(odd, i, 1, n) : update(even, i, 1, n);
    cin >> q;
    while (q--) {
        cin >> ty >> a >> b;
        if (ty == 0) {
            (v[a] & 1) ? update(odd, a, -1, n) : update(even, a, -1, n);
            (b & 1) ? update(odd, a, 1, n) : update(even, a, 1, n);
            v[a] = b;
        } else if (ty == 1) {
            cout << query(even, b) - query(even, a-1) << endl;
        } else {
            cout << query(odd, b) - query(odd, a-1) << endl;
        }
    }
}
