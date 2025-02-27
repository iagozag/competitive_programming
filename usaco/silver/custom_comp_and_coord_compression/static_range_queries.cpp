#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 4e5+10, MOD = 1e9+7;

void solve(){
	int N, Q; cin >> N >> Q;

	vector<tuple<int, int, int>> up(N); vector<pair<int, int>> qu(Q);
	set<int> st;
	for(auto& [a, b, c]: up) cin >> a >> b >> c, --b, st.insert(a), st.insert(b);
	for(auto& [a, b]: qu) cin >> a >> b, --b, st.insert(a), st.insert(b);

	int k = 0; map<int, int> mp, inv;
	for(auto& x: st) mp[x] = k, inv[k++] = x;

	vector<int> pref(k+1), bet(k+1);
	for(auto [a, b, c]: up){
		pref[mp[a]] += c, pref[mp[b]+1] -= c;
		bet[mp[a]] += c, bet[mp[b]] -= c;
	}

	for(int i = 0; i <= k; i++){
		if(i) pref[i] += pref[i-1], bet[i] += bet[i-1];
		bet[i] *= inv[i+1]-inv[i]-1;
	}

	for(auto [a, b]: qu) cout << pref[mp[b]]-(mp[a] ? pref[mp[a]-1] : 0)+(mp[b] ? bet[mp[b]-1] : 0)-(mp[a] ? bet[mp[a]-1] : 0) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
