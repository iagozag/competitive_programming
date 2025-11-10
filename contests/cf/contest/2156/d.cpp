#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int query(int i, int x){
	cout << "? " << i << ' ' << x << endl;
	int q; cin >> q;
	return q;
}

void solve(){
	int n, ans = 0; cin >> n;

	vector<int> cand, idx; for(int i = 1; i <= n-1; i++) cand.emplace_back(i), idx.emplace_back(i);
	cand.emplace_back(n);
	for(int i = 0; (1<<i) <= n; i++){
		int cnt = 0;
		for(auto x: cand) cnt += ((x>>i)&1);

		int cur = 0; vector<int> bit(n);
		for(auto j: idx) bit[j] = query(j, 1<<i), cur += bit[j];

		vector<int> cand2, idx2;
		if(cur == cnt){
			for(auto x: cand) if(((x>>i)&1) == 0) cand2.emplace_back(x);
			for(auto j: idx) if(!bit[j]) idx2.emplace_back(j);
		} else{
			ans |= 1<<i;
			for(auto x: cand) if((x>>i)&1) cand2.emplace_back(x);
			for(auto j: idx) if(bit[j]) idx2.emplace_back(j);
		}

		cand = cand2, idx = idx2;
	}

	cout << "! " << ans << endl;
}

int32_t main(){
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
