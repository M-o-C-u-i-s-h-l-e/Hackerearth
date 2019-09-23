#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second

vector<int> bit;

int query(int idx) {
    int ans = 0;
    while (idx) {
        ans += bit[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

void update(int idx, int n) {
    while (idx <= n) {
        bit[idx]++;
        idx += (idx & -idx);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, q, d;
    cin >> n >> q >> d;
    vector<int> v(n+1), pos(n+1), ans(q);
    vector<pair<pair<int, int>, int>> Q(q);
    bit.resize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    for (int i = 0; i < q; i++) {
        cin >> Q[i].F.F >> Q[i].F.S;
        Q[i].S = i;
    }
    sort(Q.begin(), Q.end(), [](pair<pair<int, int>, int> a, pair<pair<int,int>, int> b){
        return a.F.S < b.F.S;
    });
    for (int i = 1, x = 0; i <= n; i++) {
        for (int j = max(1, v[i] - d); j <= min(n, v[i] + d); j++)
            if (pos[j] <= i)
                update(pos[j], n);
        while (x < q && i == Q[x].F.S) {
            ans[Q[x].S] = query(Q[x].F.S) - query(Q[x].F.F - 1);
            x++;
        }
    }
    for (int i : ans)
        cout << i << endl;
}
