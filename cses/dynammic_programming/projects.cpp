#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>[3]); unordered_set<int> s;
    for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2], s.insert(v[i][0]), s.insert(v[i][1]);
    sort(v.begin(), v.end());
    vector<ll> hash(2*n+2); int k = 1;
    for(auto x: s) hash[k] = x;

    vector<ll> dp(2*n+2);
    for(int i = 0; i < n; i++){
        auto [a, b, p] = v[i];

    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
