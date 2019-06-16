#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        cin >> str;
        int n, times = 0;
        cin >> n;
        for (int i = 0; i <= str.size()-n; i++) {
            if (str[i] == '0') {
                for (int j = i; j < i+n; j++)
                    str[j] ^= '0' ^ '1';
                times++;
            }
        }
        bool flag = true;
        for (int i = 0; i < str.size(); i++)
            if (str[i] == '0') {
                flag = false;
                break;
            }
        (flag) ? cout << times << endl : cout << -1 << endl;
    }
}
