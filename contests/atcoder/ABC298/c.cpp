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
	int n, q; cin >> n >> q;
	vector<multiset<int>> b(MAX); vector<set<int>> c(MAX);
	for(int i = 0; i < q; i++){
		int op; cin >> op;
		if(op == 1){
			int x, y; cin >> x >> y; b[y].insert(x), c[x].insert(y);
		} else if(op == 2){
			int x; cin >> x;
			for(auto& y: b[x]) cout << y << ' ';
			cout << endl;
		} else{
			int x; cin >> x;
			for(auto& y: c[x]) cout << y << ' ';
			cout << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
