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
	vector<string> a(n); for(auto &x: a) cin >> x;
	vector<string> b(n); for(auto &x: b) cin >> x;
	for(int i = 0; i <= 30; i++){
		for(int j = 0; j <= 30; j++){
			vector<string> na(n);
			for(int l = 0; l < n; l++) for(int k = 0; k < m; k++) na[l] += a[(l+i)%n][(k+j)%m];
			if(na == b){ cout << "Yes" << endl; return; }
		}
	} 

	cout << "No" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
