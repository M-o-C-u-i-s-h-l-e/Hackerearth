#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long n, k;
    cin >> n >> k;
    vector<pair<long, long>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());
    long ans = 0;
    vector<long> v;
    for (int i = 0; i < n; i++) {
        if (ans + arr[i].first <= k) {
            v.push_back(arr[i].second);
            ans += arr[i].first;
        } else {
            break;
        }
    }
    if (v.size() > 0) {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size()-1)
                cout << ",";
        }
    } else {
        cout << -1;
    }
    cout << endl;
}
