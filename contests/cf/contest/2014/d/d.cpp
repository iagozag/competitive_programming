#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, d, k; cin >> n >> d >> k;
    vector<pii> jobs(k); forr(x, jobs) cin >> x.ff >> x.ss;

    vi st(k), end(k);
    rep(i, 0, k) st[i] = jobs[i].ff, end[i] = jobs[i].ss;
    sort(all(st)), sort(all(end));

    int mi = 1, qntmi = INF, ma = 1, qntma = 0;
    for(int i = 1; i+d-1 <= n; i++){
        pii vis = {i, i+d-1};
        int ub = upper_bound(all(st), vis.ss)-st.begin();
        int lb = lower_bound(all(end), vis.ff)-end.begin();

        int qnt = ub-lb;
        if(qnt < qntmi) mi = vis.ff, qntmi = qnt;
        if(qnt > qntma) ma = vis.ff, qntma = qnt;
    }

    cout << ma << " " << mi << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
