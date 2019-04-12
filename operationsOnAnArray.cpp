#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    long ans = LONG_MAX;
    for (int i = 0; i < n; i++) {
        long temp = 0;
        for (int j = 0; j < n; j++)
            temp += min(abs(v[i] - v[j]), v[j]);
        ans = min(ans, temp);
    }
    cout << ans << endl;
}
