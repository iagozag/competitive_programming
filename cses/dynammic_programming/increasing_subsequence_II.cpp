#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int seg[2*MAX];

int query(int a, int b){
	int ret = 0;
	for(a += MAX, b += MAX; a <= b; ++a /= 2, --b /= 2){
		if(a%2) ret += seg[a], ret %= MOD;
		if(b%2 == 0) ret += seg[b], ret %= MOD;
	}
	return ret;
}

void update(int p, int x){
	seg[p += MAX] += x, seg[p] %= MOD;
	while(p /= 2) seg[p] = seg[2*p]+seg[2*p+1], seg[p] %= MOD;
}

void solve(){
	int n; cin >> n;
	set<int> st;
	vector<int> v(n); for(auto& x: v) cin >> x, st.insert(x);

	map<int, int> mp; int k = 1;
	for(auto x: st) mp[x] = k++;
	for(auto& x: v) x = mp[x];

	memset(seg, 0, sizeof seg);

	for(int i = 0; i < n; i++){
		update(v[i], (query(0, v[i]-1)+1)%MOD);
	}

	cout << query(0, MAX-1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
