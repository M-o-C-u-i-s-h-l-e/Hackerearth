//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100001

vector<long> bit(MAX);

long query(int idx) {
    long res = 0;
    while (idx) {
        res += bit[idx];
        idx -= (idx & -idx);
    }
    return res;
}

void update(int idx, int n) {
    while (idx <= n) {
        bit[idx]++;
        idx += (idx & -idx);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long n, ans = 0, Count = 0;
        cin >> n;
        fill(bit.begin(), bit.begin() + (n + 1), 0);
        vector<int> v(n << 1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i + n] = v[i];
        }
        for (int i = (n << 1) - 1; i >= n; i--) {
            Count += query(v[i]);
            update(v[i], n);
        }
        ans ^= Count;
        for (int i = n-1; i > 0; i--) {
            Count += (v[i] - 1) - (n - v[i]);
            // Count += (v[i] << 1) - n - 1;
            ans ^= Count;
        }
        cout << ans << endl;
    }
}
