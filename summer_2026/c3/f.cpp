#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

map<int, int> nim;

int f(int x){
	if(x == 0) return 0;
	if(nim.count(x)) return nim[x];

	vector<int> vis(33); int msb = __builtin_clz(1ll)-__builtin_clz(x);
	for(int i = 1; i <= msb+1; i++){
		int left = ((1ll<<(i-1))-1)&x, right = x-left;
		right >>= i;
		vis[f(left|right)] = 1;
	}
	
	int mex = 33;
	for(int i = 0; i <= 32; i++) if(!vis[i]){ mex = i; break; }
	return nim[x] = mex;
}

void solve(){
	int n; cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int x; cin >> x;

		for(int j = 2; j*j <= x; j++) if(x%j == 0){
			int qnt = -1;
			while(x%j == 0) qnt++, x /= j;
			mp[j] |= (1<<qnt);
		}

		if(x > 1) mp[x] |= 1;
	}

	int ans = 0;
	for(auto [a, b]: mp) ans ^= f(b);
	cout << (ans == 0 ? "Arpa" : "Mojtaba") << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
