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

int MAX = 2e6+10;

void solve(){
    int n; cin >> n;
    vi a(n), exp_a(MAX);
    for(auto& x: a) cin >> x;
    for(int i = 0; i < n; i++) cin >> exp_a[a[i]];

    int m; cin >> m;
    vi b(m), exp_b(MAX);
    for(auto& x: b) cin >> x;
    for(int i = 0; i < m; i++) cin >> exp_b[b[i]];

    ll ans = 1;
    for (int i = 0; i < MAX; i++) {
        if (exp_a[i] < exp_b[i]) ans = 0;
        if (exp_a[i] > exp_b[i]) ans = (ans*2)%998244353;
    }
    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
