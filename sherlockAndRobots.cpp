//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 300001

vector<pair<int, long>> bit(MAX, {0, 0});

pair<long, long> query(int idx) {
    long res = 0, Count = 0;
    while (idx) {
        res += bit[idx].second;
        Count += bit[idx].first;
        idx -= (idx & -idx);
    }
    return {Count, res};
}

void update(int idx, int val) {
    while (idx < MAX) {
        bit[idx].first++;
        bit[idx].second += val;
        idx += (idx & -idx);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    long n, total = 0;
    cin >> n;
    vector<int> H(n+1), I(n+1);
    vector<long> ans(n+1);
    for (int i = 1; i <= n; i++)
        cin >> H[i] >> I[i];
    for (int i = n; i >= 1; i--) {
        pair<long, long> x = query(H[i] - 1);
        update(H[i], I[i]);
        long Min = x.second - (x.first * I[i]);
        long Max = ((n - i - x.first) * I[i]) - (total - x.second);
        ans[i] = Min + Max;
        total += I[i];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}
