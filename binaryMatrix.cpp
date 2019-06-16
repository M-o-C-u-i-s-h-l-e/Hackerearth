#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<pair<string, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    string str = v[n-1].first;
    int i;
    for (i = n-2; i >= 0; i--)
        if (v[i].first != str)
            break;
    cout << v[i+1].second << endl;
}
