#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m; ll k, sum = 0; cin >> n >> m >> k;
    vector<ll> v(n); for(auto& x: v) cin >> x, sum += x;
    
    for(int i = 0; i < n; i++){
        ll l = 0, r = k-sum+1, ans = r;
        while(l <= r){
            
        }
        cout << (ans == k-sum+1 ? -1 : ans) << endl;
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
