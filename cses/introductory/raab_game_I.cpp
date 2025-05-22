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
	int n, x, y; cin >> n >> x >> y;
	if(x+y > n){ cout << "NO" << endl; return; }

	vector<int> a, b;

	for(int i = 1; i <= n; i++) a.emplace_back(i);
	for(int i = 1; i <= n-x-y; i++) b.emplace_back(i);

	if(a == b){
		cout << "YES" << endl;
		for(auto z: a) cout << z << ' ';
		cout << endl;
		for(auto z: b) cout << z << ' ';
		cout << endl;
		return;
	}

	int need = n-(int)b.size(); 
	vector<int> have; for(int i = n-x-y+1; i <= n; i++) have.emplace_back(i);
	for(int k = 0; k < need; k++){
		int hx = 0, hy = 0;
		for(int i = n-x-y; i < n; i++){
			if(a[i] < have[i-(n-x-y)]) hy++;
			else if(a[i] > have[i-(n-x-y)]) hx++;
		}

		if(hx == x and hy == y){
			for(auto z: have) b.emplace_back(z);
			cout << "YES" << endl;
			for(auto z: a) cout << z << ' ';
			cout << endl;
			for(auto z: b) cout << z << ' ';
			cout << endl;
			return;
		}

		rotate(have.begin(), have.begin()+1, have.end());
	}

	cout << "NO" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
