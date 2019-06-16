#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans += a;
    }
    (ans / 2 == n - 1) ? cout << "Yes\n" : cout << "No\n";
}
