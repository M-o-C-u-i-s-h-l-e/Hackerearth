//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 500001
#define mod 1000000007

vector<int> phi(MAX), P(MAX);
vector<long> bit(1000001);

void eulerTotient() {
	for (int i = 1; i < MAX; i++)
		phi[i] = i;
	for (int i = 2; i < MAX; i++) {
		if (phi[i] == i) {
			phi[i] = i - 1;
			for (int j = i << 1; j < MAX; j += i)
				phi[j] = (phi[j] / i) * (i - 1);
        } 
    } 
}

void pillaiArithmeticFunction() {
	for (int i = 1; i < MAX; i++)
		P[i] = i;
	for (int i = 1; i < MAX; i++)
		for (int j = i << 1; j < MAX; j += i)
			P[j] += (i * phi[j / i]);
}

long query(int idx) {
	long ans = 0;
	while (idx) {
		ans += bit[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

void update(int idx, int val, int n) {
	while (idx <= n) {
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	eulerTotient();
	pillaiArithmeticFunction();
	
	int n, q;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
		update(i, P[v[i]], n);
	cin >> q;
	char c;
	int x, y;
	while (q--) {
		cin >> c >> x >> y;
		if (c == 'U') {
			update(x, P[y] - P[v[x]], n);
			v[x] = y;
		} else {
			long ans = query(y) - query(x-1);
			cout << ans % mod << endl;
		}
	}
}
