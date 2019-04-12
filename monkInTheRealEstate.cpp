#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n;
        set<int> s;
        while (n--) {
            cin >> x >> y;
            s.insert(x);
            s.insert(y);
        }
        cout << s.size() << endl;
    }
}
