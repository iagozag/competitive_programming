#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vi v(n);
    for(auto& x: v) cin >> x;

    if(n == 1){
        cout << 1 << endl << v[0] << endl;
        return;
    }

    vi ans = {v[0]};
    for(int i = 1; i < n; i++){
        ans.pb(v[i]);
        if(v[i] < v[i-1]) ans.pb(v[i]);
    }

    cout << ans.size() << endl;
    for(auto& x: ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
