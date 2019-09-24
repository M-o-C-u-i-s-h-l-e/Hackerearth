//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 500007
#define lg 19

long n, k, q;
vector<vector<long>> sp(lg, vector<long>(MAX));
vector<int> R(MAX), ans(MAX), bit(MAX, MAX);
vector<int> v[MAX];

int query(int idx) {
    int ans = MAX;
    while (idx) {
        ans = min(ans, bit[idx]);
        idx -= (idx & -idx);
    }
    return ans;
}

void update(int idx, int val) {
    while (idx < MAX) {
        bit[idx] = min(val, bit[idx]);
        idx += (idx & -idx);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
	    cin >> sp[0][i];
	    sp[0][i] %= k;
	}
	for (int l = 1; l < lg; l++)
	    for (long i = 0; i + (1 << l) <= n; i++)
	        sp[l][i] = (sp[l-1][i] * sp[l-1][i + (1 << l - 1)]) % k;
	for (int i = 0, l; i < q; i++) {
	    cin >> l >> R[i];
	    R[i]--;
	    v[l-1].push_back(i);
	}
	for (int i = n-1; i >= 0; i--) {
	    long j = i, cur = 1;
	    for (long l = lg - 1; l >= 0; l--) {
	        if (j + (1 << l) < n && (cur * sp[l][j]) % k != 0) {
	            cur = (cur * sp[l][j]) % k;
	            j += (1 << l);
	        }
	    }
	    if ((cur * sp[0][j]) % k == 0)
	        update(j, j - i + 1);
	    for (int j : v[i])
	        ans[j] = query(R[j]);
	}
	for (int i = 0; i < q; i++)
	    cout << (ans[i] >= MAX ? -1 : ans[i]) << ' ';
}
