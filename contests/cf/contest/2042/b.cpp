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
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		int a; cin >> a; --a; v[a]++;
	}

	int ans = 0;
	vector<int> c; bool alice = 1;
	for(int i = 0; i < n; i++) if(v[i]){
		if(v[i] == 1){ 
			if(alice) ans += 2;
			alice = !alice;
			continue;
		}
		c.emplace_back(v[i]);
	}

	ans += c.size();

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
