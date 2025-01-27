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
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n); vector<int> p;
	for(int i = 0; i < n; i++) cin >> a[i], p.emplace_back(a[i]); 
	for(int i = 0; i < n; i++) cin >> b[i], p.emplace_back(b[i]);
	sort(a.begin(), a.end()), sort(b.begin(), b.end());
	sort(p.begin(), p.end()), p.erase(unique(p.begin(), p.end()), p.end());
	
	int ans = 0;
	for(auto& x: p){
		int qnt = n-((int)(lower_bound(b.begin(), b.end(), x)-b.begin()));
		int pos = n-((int)(lower_bound(a.begin(), a.end(), x)-a.begin()));
		if(qnt-pos <= k) ans = max(ans, x*(qnt));
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
