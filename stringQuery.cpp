//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> bit;

int query(int idx) {
    int ans = 0;
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

    string str;
    cin >> str;
    int n = str.size();
    bit.resize(n + 1);
    for (int i = 1; i <= n; i++)
        update(i, 1, n);
    vector<vector<int>> v(26);
    for (int i = 0; i < n; i++)
        v[str[i] - 'a'].push_back(i + 1);
    int q, pos, idx;
    char c;
    cin >> q;
    while (q--) {
        cin >> pos >> c;
        idx = query(v[c - 'a'][pos - 1]);
        update(v[c - 'a'][pos - 1], -1, n);
        v[c - 'a'].erase(v[c - 'a'].begin() + (pos - 1));
        str.erase(str.begin() + (idx - 1));
    }
    cout << str;
}
