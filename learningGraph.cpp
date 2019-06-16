#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back({v[y-1], y});
        adj[y-1].push_back({v[x-1], x});
    }
    for (int i = 0; i < n; i++)
        sort(adj[i].begin(), adj[i].end());
    for (int i = 0; i < n; i++)
        (adj[i].size() < k) ? cout << -1 << endl : cout << adj[i][adj[i].size()-k].second << endl;
}
