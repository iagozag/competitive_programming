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
	vector<int> v(n); for(auto& x: v) cin >> x;
	for(int i = 0; i < n-1; i++){
		cout << v[i] << ' ';
		if(v[i] < v[i+1])
			for(int j = v[i]+1; j < v[i+1]; j++) cout << j << ' ';
		else 
			for(int j = v[i]-1; j > v[i+1]; j--) cout << j << ' ';
	}
	cout << v[n-1] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
