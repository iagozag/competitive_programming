#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, q; cin >> n >> q;
	vector<int> p(n); for(auto& x: p) cin >> x, --x;
	string s; cin >> s;

	vector<int> st, end, vis(n);
	for(int i = 0; i < n; i++){
		if(!vis[p[i]]) vis[p[i]] = 1, st.emplace_back(min(p[i], i)), end.emplace_back(max(p[i], i));
	}
	sort(st.begin(), st.end()), sort(end.begin(), end.end());

	vis = vector<int>(n);
	ll qnt = 0;
	for(int i = 0; i < n-1; i++){
		if(s[i] == 'L' and s[i+1] == 'R'){
			vis[i] = vis[i+1] = 1;
			ll r = lower_bound(st.begin(), st.end(), i+1)-st.begin();
			ll l = upper_bound(end.begin(), end.end(), i)-end.begin();
			qnt += r-l;
		}
	}

	for(int i = 0; i < q; i++){
		int idx; cin >> idx; --idx;

		if(vis[idx]){
			int l;
			if(s[idx] == 'R') l = idx-1;
			else l = idx;

			vis[l] = vis[l+1] = 0;
			ll lr = lower_bound(st.begin(), st.end(), l+1)-st.begin();
			ll ul = upper_bound(end.begin(), end.end(), l)-end.begin();
			qnt -= lr-ul;
		}

		s[idx] = (s[idx] == 'L' ? 'R' : 'L');

		int l = -1;
		if(s[idx-1] == 'L' and s[idx] == 'R') l = idx-1;
		else if(s[idx] == 'L' and s[idx+1] == 'R') l = idx;

		if(l != -1){
			vis[l] = vis[l+1] = 1;
			ll lr = lower_bound(st.begin(), st.end(), l+1)-st.begin();
			ll ul = upper_bound(end.begin(), end.end(), l)-end.begin();
			qnt += lr-ul;
		}

		cout << (!qnt ? "YES" : "NO") << endl;
	}
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
