//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define MAX 100001

int n, q, x;
string str;
char c;
vector<pair<int, string>> v(MAX);
map<string, pair<int, int>> mp;
vector<int> bit(MAX);

int query(int idx) {
    int res = 0;
    for (; idx; idx -= (idx & -idx))
        res += bit[idx];
    return res;
}

void update(int idx, int val) {
    for (; idx < MAX; idx += (idx &-idx))
        bit[idx] += val;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i].S >> v[i].F;
    sort(v.begin() + 1, v.begin() + (n + 1));
    for (int i = 1; i <= n; i++)
        mp[v[i].S] = {i, 0};
    cin >> q;
    while (q--) {
        cin >> c;
        if (c == '+') {
            cin >> str;
            auto itr = mp.find(str);
            update(v[itr->S.F].F, 1);
            itr->S.S++;
        } else if (c == '-') {
            cin >> str;
            auto itr = mp.find(str);
            if (itr != mp.end() && itr->S.S > 0) {
                update(v[itr->S.F].F, -1);
                itr->S.S--;
            }
        } else {
            cin >> x;
            cout << query(MAX - 1) - query(x) << endl;
        }
    }
}
