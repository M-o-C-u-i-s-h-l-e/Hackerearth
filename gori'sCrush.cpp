//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, q, k;
    cin >> n >> q >> k;
    vector<int> v(n), comp(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        comp[i] = v[i];
    }
    sort(comp.begin(), comp.end());
    for (int i = 0, ty, a, b, c, d, pos1, pos2, ans; i < q; i++) {
        cin >> ty >> a >> b;
        if (ty == 0) {
            pos1 = lower_bound(comp.begin(), comp.end(), v[a - 1]) - comp.begin();
            comp.erase(comp.begin() + pos1);
            pos2 = lower_bound(comp.begin(), comp.end(), b) - comp.begin();
            comp.insert(comp.begin() + pos2, b);
            v[a - 1] = b;
        } else {
            cin >> c >> d;
            pos1 = upper_bound(comp.begin(), comp.end(), min(b, d)) - comp.begin();
            pos2 = upper_bound(comp.begin(), comp.end(), max(a, c) - 1) - comp.begin();
            ans = pos1 - pos2;
            (ans >= k) ? cout << "Propose\n" : cout << "Do not propose\n";
        }
    }
}
