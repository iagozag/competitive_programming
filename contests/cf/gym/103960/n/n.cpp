#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace __gnu_pbds;

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
typedef tree<pair<ll, pll>, null_type, greater<pair<ll, pll>>, rb_tree_tag, tree_order_statistics_node_update> sett;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vl a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	int k, l; cin >> k >> l;
	
	sett st;
	rep(i, 0, k) st.insert({a[i]+b[i], {a[i], b[i]}});
	
	ll ans = 0, sum = 0; int cnt = 0;
	forr(x, st){
	    if(cnt < l) sum += x.ff;
	    else sum += x.ss.ff;
	    cnt++;
	}
	
	ckmax(ans, sum);

	int le = k-1, ri = n-1;
	rep(i, 0, k){
        pair<ll, pll> rem = {a[le]+b[le], {a[le], b[le]}};

        sum -= rem.ss.ff;
	    if(st.order_of_key(rem) < l) sum -= rem.ss.ss;

        pair<ll, pll> prev = *st.find_by_order(l-1);

        st.erase(rem);

        pair<ll, pll> np = {a[ri]+b[ri], {a[ri], b[ri]}};
        st.insert(np);

        if(st.order_of_key(np) < l) sum += np.ff;
        else{
            sum += np.ss.ff;
            if(*st.find_by_order(l-1) != prev) sum += (*st.find_by_order(l-1)).ss.ss;
        }
	    
	    le--, ri--;
	    ckmax(ans, sum);
	}
	
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
