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
	vector<int> v(2*n+1); set<int> st; for(int i = 1; i < 2*n+1; i++) cin >> v[i], st.insert(v[i]);
	sort(v.begin(), v.end()); vector<int> nv;
	for(int i = 1; i < n+1; i++)
		v[0] += v[2*n+1-i]-v[i], nv.emplace_back(v[2*n+1-i]), nv.emplace_back(v[i]);

	if(st.count(v[0])){
		v[0] = v[2*n];
		for(int i = 1; i < 2*n-1; i += 2) swap(v[i], v[i+1]), v.back() -= v[i]-v[i+1];
		swap(v[2*n], v[2*n-1]);
		v[2*n-1] += v.back();
	}
	else for(int i = 1; i < 2*n+1; i++) v[i] = nv[i-1];

	for(auto x: v) cout << x << ' ';
	cout << endl;
	return;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
