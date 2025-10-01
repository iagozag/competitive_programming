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
	vector<int> v(n), vis(n+1);
	for(auto& x: v){
		cin >> x, vis[x]++;
	}

	if(vis[0] == 1){
		int num = 0;
		for(int i = 0; i <= n; i++) if(!vis[i]) num = i;
		for(int i = 0; i < n; i++) if(!v[i]) v[i] = num;
	}

	int l = 0, r = n-1;
	while(l < n and v[l] and l+1 == v[l]) l++;
	while(r >= 0 and v[r] and r+1 == v[r]) r--;

	if(l >= r){ cout << 0 << endl; return; }
	else cout << r-l+1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
