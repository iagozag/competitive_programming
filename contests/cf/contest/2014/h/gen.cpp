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

int maxn = 2e5, maxq = 2e5;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
    if(maxn == 0 or maxq == 0){ cout << "0 0" << endl; return; }
    int n = uniform(1, maxn), q = uniform(1, maxq);
    maxn -= n, maxq -= q;
    cout << n << " " << q << endl;
    rep(i, 0, n) cout << uniform(1, 1e6) << " \n"[i==n-1];
    rep(i, 0, q){ int a = uniform(1, n), b = uniform(1, n); cout << min(a, b) << " " << max(a, b) << endl; }
}

int main(){ _
    int ttt = uniform(1, 1e4); 

    cout << ttt << endl;

    while(ttt--) solve();

    exit(0);
}
