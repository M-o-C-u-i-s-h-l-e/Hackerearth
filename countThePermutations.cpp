//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 100001
#define MAX 200001
#define mod 1000000007

int n, a[MAXN], b[MAXN], bit[MAX];
long ans = 0, fact[MAX], com[MAX], cnt[MAX];

void update(int idx, long val) {
	for (; idx < MAX; idx += (idx & -idx))
		bit[idx] += val;
}

long query(int idx) {
	long res = 0;
	for (; idx; idx -= (idx & -idx))
		res += bit[idx];
	return res;
}

long power(long a, long b) {
	long ans = 1;
	while (b) {
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	fact[0] = com[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		com[i] = power(fact[i], mod - 2);
	}
	long comb = fact[n];
	for (int i = 1; i < MAX; i++)
		comb = (comb * com[cnt[i]]) % mod;
	for (int i = 1; i < MAX; i++)
		update(i, cnt[i]);
	for (int i = 1; i <= n; i++) {
		comb = (comb * power(n - i + 1, mod - 2)) % mod;
		ans = (ans + comb * query(b[i] - 1)) % mod;
		comb = (comb * cnt[b[i]]) % mod;
		cnt[b[i]]--;
		if (cnt[b[i]] < 0)
			break;
		update(b[i], -1);
	}
	cout << ans << endl;
}
