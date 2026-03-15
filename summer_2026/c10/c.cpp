#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<int> pos;

void gen(int num, int i, int can){
	if(!can){ pos.emplace_back(num); return; }
	if(i == n) return;

	gen(num, i+1, can);
	gen(num|(1ll<<i), i+1, can-1);
}

void solve(){
	cin >> n >> m;
	vector<pair<int, int>> v;
	for(int i = 0; i < m; i++){
		string s; cin >> s;

		int num = 0;
		for(int j = 0; j < n; j++) if(s[j] == '1') num |= (1ll<<j);

		int qnt; cin >> qnt;
		v.emplace_back(num, qnt);
	}

	gen(0, 0, v[0].second);

	for(auto& p: pos){
		int num = v[0].first;
		for(int i = 0; i < n; i++){
			if(!(p&(1ll<<i))) num ^= (1ll<<i);
		}
		p = num;
	}
	
	int sz = pos.size(); vector<int> can(sz, 1); 
	for(int k = 0; k < sz; k++){
		for(int i = 1; i < m; i++){
			int sum = 0;
			for(int j = 0; j < n; j++) if(((1ll<<j)&v[i].first) == ((1ll<<j)&pos[k])) sum++;

			if(sum != v[i].second){
				can[k] = 0;
				break;
			}
		}
	}

	int ans = 0;
	for(auto x: can) ans += x;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
