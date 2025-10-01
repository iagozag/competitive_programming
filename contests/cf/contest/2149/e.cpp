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
	int n, k, L, R; cin >> n >> k >> L >> R;
	vector<int> v(n); for(auto& x: v) cin >> x;

	map<int, int> mp; int qnt = 0, ans = 0;
	auto tadd = [&](int x) -> bool{
		x = v[x];
		return mp[x] == 0;
	};
	auto add = [&](int x) -> void{
		x = v[x];
		if(mp[x] == 0) qnt++;
		mp[x]++;
	};
	auto rem = [&](int x) -> void{
		x = v[x];
		if(mp[x] == 1) qnt--;
		mp[x]--;
	};
	vector<int> pos(n); int j = 0;
	for(int i = 0; i < n; i++){
		while(j < n and qnt < k) add(j++);
		pos[i] = j;

		rem(i);
	}

	int l = 0, r2 = 0;
	while(true){
		if(n-l < L) break;

		while(r2 < n and (qnt < k or (qnt == k and !tadd(r2))))
			add(r2++);

		if(qnt == k){
			int needl = l+L-1, needr = l+R-1;
			needl = max(needl, pos[l]-1);
			needr = min(needr, r2-1);
			ans += max(0LL, needr-needl+1);
		}

		rem(l++);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
