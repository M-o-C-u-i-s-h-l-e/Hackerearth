//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100001

vector<vector<int>> bit(2, vector<int>(MAX, 0));

int query(int k, int idx) {
    int res = 0;
    while (idx) {
        res += bit[k][idx];
        idx -= (idx & -idx);
    }
    return res;
}

void update(int k, int idx) {
    while (idx < MAX) {
        bit[k][idx]++;
        idx += (idx & -idx);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, q, ty, l, r, val, k = 0, x, y;
    cin >> n;
    string str;
    cin >> str;
    for (int i = n-1; i >= 0; i--) {
        if (str[i] == '1')
            update(k, i+1);
        k = (k + 1) % 2;
    }
    cin >> q;
    while (q--) {
        cin >> ty;
        if (ty == 0) {
            cin >> l >> r;
            x = query(0, r+1) - query(0, l);
            y = query(1, r+1) - query(1, l);
            k = (n - 1 - r) % 2;
            l = (k == 0) ? (x + (y << 1)) : ((x << 1) + y);
            cout << l % 3 << endl;
        } else {
            cin >> l;
            k = (n - 1 - l) % 2;
            if (str[l] == '0') {
                update(k, l+1);
                str[l] = '1';
            }
        }
    }
}
