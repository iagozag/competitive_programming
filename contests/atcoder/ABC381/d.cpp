#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> tmp(n), v; for(auto& x: tmp) cin >> x;
	int l = 0, r = 0;
	while(r < n){
		while(r < n and tmp[l] == tmp[r]) r++;

		if(r-l > 1){
			v.emplace_back(tmp[l]);
			if(r-l > 2) v.emplace_back(tmp[l]);
		} else v.emplace_back(0);
		l = r;
	}

	l = 0, r = 0;
	int ans = 0; set<int> st; n = v.size();
	while(r < n){
		if(l == r and !v[l]){ l++, r++; continue; }
		while(r < n and v[r] and !st.count(v[r])) st.insert(v[r++]);
		ans = max(ans, r-l);
		st.erase(v[l++]);
	}

	cout << ans*2 << endl;	

}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
