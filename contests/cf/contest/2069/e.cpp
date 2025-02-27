#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int seg[4*MAX] = {0};
int n;

int query(int p, int l, int r, int a, int b){
	if(b < l or a > r) return LINF;
	if(a <= l and r <= b) return seg[p];
	int m = l+(r-l)/2;
	return min(query(p*2, l, m, a, b), query(p*2+1, m+1, r, a, b));
}

int update(int p, int l, int r, int idx, int x){
	if(idx < l or idx > r) return seg[p];
	if(l == r) return seg[p] += x;
	int m = l+(r-l)/2;
	return seg[p] = min(update(p*2, l, m, idx, x), update(p*2+1, m+1, r, idx, x));
}

void solve(){
	cin >> n;
	int ans = 0;
	vector<int> v(n); 
	for(auto& x: v){ 
		cin >> x; ans += (x != 0);
		if(x < 200000) update(1, 0, 199999, x, 1); 
	}

	int i = 0;
	for(; i < n; i++){
		if(v[i] >= 200000) continue;
		update(1, 0, 199999, v[i], -1);

		if(v[i] == 0){ ans++; break; }

		if(query(1, 0, 199999, 1, v[i])) break;
	}

	cout << ans << endl;

	for(++i; i < n; i++) if(v[i] < 200000) update(1, 0, 199999, v[i], -1);
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
