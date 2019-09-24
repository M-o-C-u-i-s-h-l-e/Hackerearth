//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> phi;

void eulerTotient(int n) {
    for (int i = 1; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            phi[i] = i - 1;
            for (int j = i << 1; j <= n; j += i)
                phi[j] = (phi[j] / i) * (i - 1);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, Count = 0;
    cin >> n;
    phi.resize(n + 1);
    eulerTotient(n);
    cout << phi[n] << endl;
}
