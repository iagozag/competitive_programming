#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(vector<string> v){
	cout << "YES" << endl;
	for(auto s: v) cout << s << endl;
}

void solve(){
	int n; cin >> n;
	vector<string> v(n); for(auto& x: v) cin >> x;

	for(int i = 0; i < n; i++){
		if(v[i][0] == 'O' and v[i][1] == 'O'){
			v[i][0] = v[i][1] = '+';
			return yes(v);
		} else if(v[i][3] == 'O' and v[i][4] == 'O'){
			v[i][3] = v[i][4] = '+';
			return yes(v);
		}
	}

	cout << "NO" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
