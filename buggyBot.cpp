#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    set<int> graph[n+1], ans, temp[n+1];
    vector<int> ia(k), ib(k), pos(k+1), ee(n+1);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        graph[a].insert(b);
    }
    for (int i = 0; i < k; i++)
        cin >> ia[i] >> ib[i];
    pos[0] = 1;
    int cp = 1;
    for (int i = 0; i < k; i++) {
        if (cp == ia[i])
            cp = ib[i];
        pos[i+1] = cp;
    }
    for (int i = 1; i <= n; i++)
        ee[i] = i;
    ans.insert(pos[k]);
    for (int i = k-1; i >= -1; i--) {
        int cnode = pos[i+1];
        for (int j : graph[cnode]) {
            ans.insert(ee[j]);
            temp[j].insert(cnode);
        }
        graph[cnode].clear();
        if (i >= 0) {
            ee[ia[i]] = ee[ib[i]];
            for (int j : temp[ia[i]])
                graph[j].insert(ia[i]);
            temp[ia[i]].clear();
        }
    }
    vector<int> res(ans.begin(), ans.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}
