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
	int n, m; cin >> n >> m;
	vector<int> v(n); for(auto& x: v) cin >> x;
	for(int i = 0; i < n; i++){
		if(i and v[i-1]-v[i] > m) v[i] = v[i-1]-m;
		else if(i < n-1 and v[i+1]-v[i] > m) v[i] = v[i+1]-m;
	}

	for(int i = n-1; i >= 0; i--){
		if(i and v[i-1]-v[i] > m) v[i] = v[i-1]-m;
		else if(i < n-1 and v[i+1]-v[i] > m) v[i] = v[i+1]-m;
	}

	for(int i = 0; i < n; i++) cout << v[i] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
