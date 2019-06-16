#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int ans = 0, Count = 0;
        for (int i = 0; i < n; i++) {
            if (c - v[i] >= 0) {
                c -= v[i];
                Count++;
            } else {
                break;
            }
        }
        cout << Count << endl;
    }
}
