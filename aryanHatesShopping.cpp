#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    multiset<long long> s;
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        if (temp == 0) {
            if (s.size() < x)
                s.clear();
            else {
                auto itr = s.end();
                for (int i = 0; i < x; i++) {
                    --itr;
                    s.erase(itr);
                }
            }
        } else {
            s.insert(temp);
        }
    }
    long long total = 0;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        total += *itr;
    cout << total << endl;
}
