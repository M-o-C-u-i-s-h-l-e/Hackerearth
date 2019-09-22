#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100001
#define mod 1000000007

long bit[MAX][2];
long a[MAX], bit1[MAX];

void update(int idx, long val, int pos) {
	while (idx < MAX) {
		bit[idx][pos] = (bit[idx][pos] + val) % mod;
		idx += (idx & -idx);
	}
}

void update1(int idx, long val) {
	while (idx < MAX) {
		bit1[idx] += val;
		idx += (idx & -idx);
	}
}

long get(int idx, int pos) {
	long res = 0;
	while (idx) {
		res = (res + bit[idx][pos]) % mod;
		idx -= (idx & -idx);
	}
	return res;
}

long get1(int idx) {
	long res = 0;
	while (idx) {
		res = (res + bit1[idx]) % mod;
		idx -= (idx & -idx);
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	long ans = 0, x, y;
	for (int i = 1; i <= n; i++) {
		x = get(a[i] - 1, 1);
		y = (get(MAX - 1, 0) - get(a[i], 0) + mod) % mod;
		x = (x + get1(a[i] - 1)) % mod;
		y = (y + (get1(MAX - 1) - get1(a[i]))) % mod;
		ans = (ans + x + y) % mod;
		update1(a[i], 1);
		update(a[i], x, 0);
		update(a[i], y, 1);
	}
	cout << ans << endl;
}
