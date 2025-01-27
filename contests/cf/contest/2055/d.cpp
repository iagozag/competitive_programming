#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k, l;

bool good(vector<int> nv, int m){
	long double x = (long double)m/2.0;
	
	vector<long double> has(n, x), v(nv.begin(), nv.end()); has[0] -= v[0];

	v[0] = 0; v.emplace_back(l);
	for(int i = n-1; i >= 0; i--){
		if(v[i+1]-v[i] > k){
			long double mi = min(has[i], (v[i+1]-k)-v[i]);
			has[i] -= mi, v[i] += mi;
		} else if(v[i+1]-v[i] < k){
			long double mi = min(has[i], v[i]-(v[i+1]-k));
			has[i] -= mi, v[i] -= mi;
		}
	}

	long double cur = 0;
	for(int i = 0; i < n; i++){
		if(cur-v[i] < k) cur = v[i]+k;
		if(cur < v[i+1]){
			if(has[i] >= v[i+1]-cur){
				has[i] -= v[i+1]-cur;
				has[i+1] = max(has[i+1], has[i]);
				cur = v[i+1];
			} else return false;
		}
	}

	return cur >= l;
}

void solve(){
	cin >> n >> k >> l;
	vector<int> v(n); for(auto& x: v) cin >> x;

	int le = v[0]*2, r = 4e8, ans = r;
	while(le <= r){
		int m = le+(r-le)/2;
		if(good(v, m)) ans = m, r = m-1;
		else le = m+1;
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
