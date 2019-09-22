#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int n, q;
vector<vector<int>> bit;
 
void update(int idx, int pos, int val) {
    while (idx <= n) {
        bit[idx][pos] += val;
        idx += (idx & -idx);
    }
}
 
vector<int> get(int idx) {
    vector<int> v(26, 0);
    while (idx) {
        for (int i = 0; i < 26; i++)
            v[i] += bit[idx][i];
        idx -= (idx & -idx);
    }
    return v;
}
 
bool check(vector<int> &v1, vector<int> &v2) {
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if (abs(v1[i] - v2[i]) & 1) {
            if (!flag)
                return false;
            flag = false;
        }
    }
    return true;
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    string str;
    cin >> str;
    str = " " + str;
    bit.resize(n+1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++)
        update(i, str[i] - 'a', 1);
    while (q--) {
        int ty, a, b;
        char c;
        cin >> ty;
        if (ty == 1) {
            cin >> a >> c;
            update(a, str[a] - 'a', -1);
            update(a, c - 'a', 1);
            str[a] = c;
        } else if (ty == 2) {
            cin >> a >> b;
            vector<int> v1 = get(a - 1);
            vector<int> v2 = get(b);
            (check(v1, v2)) ? cout << "yes\n" : cout << "no\n";
        }
    }
}
