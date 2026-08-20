#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

int32_t main(){
    int n; cin >> n;
    vector<int> v(n); for(auto& x: v) cin >> x;
    sort(v.begin(), v.end());
    int ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i], ans += sum;
    }
    cout << ans << endl;
    exit(0);
}