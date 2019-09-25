//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 100001
#define F first
#define S second

long n, k, x;
long bit[2][3 * MAX];
int arr[3][MAX];

long query(int pos, int idx) {
    long res = 0;
    for (; idx; idx -= (idx & -idx))
        res += bit[pos][idx];
    return res;
}

void update(int pos, int idx, int val) {
    for (; idx <= 3 * MAX; idx += (idx & -idx))
        bit[pos][idx] += val;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        memset(bit, 0, sizeof(bit));
        cin >> n >> k;
        vector<pair<long, pair<int, int>>> v;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            v.push_back({x, {i, 0}});
            v.push_back({x - k, {i, 1}});
            v.push_back({x + k, {i, 2}});
        }
        sort(v.begin(), v.end());
        int Count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i == 0 || v[i - 1].F != v[i].F)
                Count++;
            arr[v[i].S.S][v[i].S.F] = Count;
        }
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            long sum = 0;
            sum += query(0, arr[1][i]);
            sum += query(1, 3 * MAX - arr[2][i] + 1);
            update(0, arr[0][i], i);
            update(1, 3 * MAX - arr[0][i] + 1, i);
            ans += (sum * (n - i + 1));
        }
        cout << ans << endl;
    }
}
