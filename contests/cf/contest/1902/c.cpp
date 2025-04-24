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
	int n; cin >> n; int g = 0;
	vector<int> v(n); set<int> st;
	for(int i = 0; i < n; i++) cin >> v[i], st.insert(v[i]);

 	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++){
		if(i) g = __gcd(g, v[i]-v[i-1]);
	}

	if(n == 1){ cout << 1 << endl; return; }

	int k = v.back();
	while(st.count(k)) k -= g;
	v.emplace_back(k);
	 
 	sort(v.begin(), v.end());

	int ans = 0;
	for(int i = 0; i < n; i++) ans += (v.back()-v[i])/g;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
