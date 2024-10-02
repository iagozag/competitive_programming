#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    set<int> s1, s2;
    for(int i = 0; i < n; i++){ int a; cin >> a; s1.insert(a); }
    for(int i = 0; i < m; i++){ int a; cin >> a; s2.insert(a); }

    int ans = 0;
    for(auto& x: s1){
        auto lb = s2.lower_bound(x-k);
        if(lb != s2.end() and abs((*lb)-x) <= k) ans++, s2.erase(lb);
    }
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
