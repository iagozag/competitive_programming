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
	map<int, int> qnt, st; vector<int> pos;
	for(int i = 0; i < n; i++){
		vector<int> pos2 = {v[i]}; 
		map<int, int> st2; qnt[v[i]]++, st2[v[i]]++;
		for(auto p: pos){

			int g = __gcd(p, v[i]);
			qnt[g] += st[p];

			if(st2[g] == 0) pos2.emplace_back(g);
			st2[g] += st[p];
		}

		swap(pos, pos2);
		swap(st, st2);
	}

	int q; cin >> q;
	for(int i = 0; i < q; i++){ int x; cin >> x; cout << qnt[x] << endl; }
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
