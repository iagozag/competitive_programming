#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
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
    int ans = 0;
    vi v(4); ii p = {1, 1};
    for(auto& x: v) cin >> x;
    if(v[0] == 0){
        cout << 1 << endl;
        return;
    }

    ans += v[0], p.f += v[0], p.s += v[0];

    int less = min(v[1], v[2]);
    if(less > 0) ans += less*2, v[1] -= less, v[2] -= less;

    if(v[3] >= p.f) ans += p.f, p.f = 0, p.s = 0;
    else ans += v[3], p.f -= v[3], p.s -= v[3];

    if(p.f > 0 && p.s > 0){
        if(max(v[1], v[2]) >= p.f) ans += p.f;
        else ans += max(v[1], v[2]);
    }

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
