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

bool check(long long n) {
    if (n < 0)
        return false;
    string s = to_string(n);
    return (s[0] == s[s.size() - 1]) ? true : false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long n, q, ty, a, b;
    cin >> n >> q;
    vector<long long> v(n+1);
    vector<bool> flag(n+1, false);
    bit.resize(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        if (check(v[i]))
            update(i, 1, n), flag[i] = true;
    while (q--) {
        cin >> ty >> a >> b;
        if (ty == 1) {
            cout << query(b) - query(a-1) << endl;
        } else {
            v[a] = b;
            if (flag[a])
                update(a, -1, n), flag[a] = false;
            if (check(b))
                update(a, 1, n), flag[a] = true;
        }
    }
}
