//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long n, q, ty, a, b, c, ans;
vector<vector<long>> bit;

long query(long idx, long pos) {
    long res = 0;
    while (idx) {
        res += bit[pos][idx];
        idx -= (idx & -idx);
    }
    return res;
}

long rangeQuery(int pos, int idx1, int idx2) {
    return query(idx2, pos) - query(idx1 - 1, pos);
}

void update(int idx, int pos, long val) {
    while (idx <= n) {
        bit[pos][idx] += val;
        idx += (idx & -idx);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> q;
    bit.resize(2, vector<long>(n+1));
    for (long i = 1, x; i <= n; i++) {
        cin >> x;
        update(i, 0, x);
        update(i, 1, i * x);
    }
    while (q--) {
        cin >> ty >> a >> b;
        if (ty == 1) {
            cin >> c;
            ans = 0;
            if (a <= b) {
                ans = rangeQuery(1, b, c) - (rangeQuery(0, b, c) * a);
            } else if (a <= c) {
                ans = rangeQuery(1, a, c) - (rangeQuery(0, a, c) * a) + (rangeQuery(0, b, a) * a) - rangeQuery(1, b, a);
            } else {
                ans = (rangeQuery(0, b, c) * a) - rangeQuery(1, b, c);
            }
            cout << ans << endl;
        } else {
            update(a, 0, b);
            update(a, 1, a * b);
        }
    }
}
