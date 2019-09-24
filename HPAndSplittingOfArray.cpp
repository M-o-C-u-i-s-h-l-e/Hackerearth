//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000001
 
vector<int> bit(MAX);
 
int query(long idx) {
    int res = 0;
    while (idx) {
        res += bit[idx];
        idx -= (idx & -idx);
    }
    return res;
}
 
void update(int idx) {
    while (idx < MAX) {
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
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        v.push_back(v[1]);
        v.erase(v.begin() + 1);
        fill(bit.begin(), bit.end(), 0);
        long ans = 0;
        for (int i = n; i >= 1; i--) {
            ans += query(v[i] - 1);
            update(v[i]);
        }
        cout << ans << ' ';
        for (int i = 1, add, sub; i < n; i++) {
            sub = query(v[i] - 1);
            add = n - query(v[i]);
            ans += add - sub;
            cout << ans << ' ';
        }
        cout << endl;
    }
}
