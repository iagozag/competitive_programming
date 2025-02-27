#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<int> v, nv;
unordered_set<int> ans;

void f(int i){
	if(i == n){
		int y = 0;
		for(int j = 0; j < n; j++) y ^= nv[j];
		ans.insert(y);
		return;
	}

	for(int j = 0; j <= i; j++) if(nv[j]){
		nv[j] += v[i], nv[i] -= v[i];
		f(i+1);
		nv[j] -= v[i], nv[i] += v[i];
	}
}

void solve(){
	cin >> n; v = vector<int>(n); 
	for(auto& x: v) cin >> x;
	nv = v;

	f(0);

	cout << ans.size() << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

