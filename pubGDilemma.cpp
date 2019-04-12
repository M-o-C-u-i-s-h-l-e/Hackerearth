#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n+1), ans;
    map<int, bool> m;
    for (int i = 0; i <= n; i++)
        cin >> arr[i];
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end(), greater<int>());
    for (int i = 0; i <= n; i++) {
        if (m.find(temp[i]) == m.end()) {
            vector<int> v(temp.begin(), temp.end());
            v.erase(v.begin() + i);
            bool flag = true;
            for (int j = 0; j < n; j++) {
                int sum = 0, s1 = 0;
                for (int k = 0; k <= j; k++)
                    sum += v[k];
                for (int k = j+1; k < n; k++)
                    s1 += min(j+1, v[k]);
                if (sum > (j+1) * j + s1) {
                    flag = false;
                    break;
                }
                if (j == n-1 && sum % 2 != 0) {
                    flag = false;
                    break;
                }
            }
            m[temp[i]] = flag;
        }
    }
    for (int i = 0; i <= n; i++)
        if (m[arr[i]])
            ans.push_back(i+1);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}
