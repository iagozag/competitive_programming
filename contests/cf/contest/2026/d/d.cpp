#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<ll> v;

void solve(){
	cin >> n; v = vector<ll>(n);
	for(auto& x: v) cin >> x;
	vector<ll> pos; ll cnt = n;
	for(ll i = 0; i < n*(n+1)/2; i += cnt--){
		pos.emplace_back(i);
	}

	vector<ll> pref(n), cond(n), pcond(n); 
	for(int i = 0; i < n; i++) pref[i] = (i ? pref[i-1]+v[i] : v[i]);
	for(int i = n-1; i >= 0; i--) cond[i] = (i == n-1 ? v[i] : cond[i+1]+v[i]*(n-i));
	for(int i = 0; i < n; i++) pcond[i] = (i ? pcond[i-1]+cond[i] : cond[i]);

	auto sum = [&](int l1, int r1, int l2, int r2){
		
	};

	int Q; cin >> Q;
	for(int i = 0; i < Q; i++){
		int l, r; cin >> l >> r; --l, --r;
		int ub = upper_bound(pos.begin(), pos.end(), l)-pos.begin(); ub--;
		int ub2 = upper_bound(pos.begin(), pos.end(), r)-pos.begin(); ub2--;

		int l1 = ub, r1 = l-pos[ub], l2 = ub2, r2 = r-pos[ub2];
		
		if(l1 == l2) cout << sum(l1, r1, l2, r2) << endl;
		else cout << pcond[l2-1]-pcond[l1]+sum(l1, r1, l1, pos[ub+1]-1)+sum(l2, 0, l2, r2) << endl
	}
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
