#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int query(int x){
	cout << "? " << x << endl;
	int q; cin >> q;
	return q;
}

void yes(int ans){
	cout << "! " << ans << endl;
}

void solve(){
	int f = query(0), qnt = __builtin_popcount(f);

	vector<int> X(60, -1);

	for(int i = 0; i < 60; i += 2){
		int u = (1LL<<i)+(1LL<<(i+1));
		int q = query(u), pc = __builtin_popcount(q);
		if(q == 0) return yes(u);

		if(pc == qnt-2) X[i] = X[i+1] = 1;
		else if(pc == qnt+2) X[i] = X[i+1] = 0;
	}

	for(int i = 0; i < 60; i += 2) if(X[i] == -1){
		int sec1 = uniform(0, 1), sec2 = uniform(0, 1);
		
		int j = i+2;
		while(j < 60 and X[j] != -1) j += 2;

		if(j >= 60) continue;

		int u = (1LL<<(i+sec1))+(1LL<<j);
		int q = query(u), pc = __builtin_popcount(q);
		if(q == 0) return yes(u);

		if(pc == qnt-2){
			if(sec1) X[i] = 0, X[i+1] = 1;
			else X[i] = 1, X[i+1] = 0;
			
			if(sec2) X[j] = 0, X[j+1] = 1;
			else X[j] = 1, X[j+1] = 0;
		}
	}
	
	for(int i = 0; i < 60; i += 2) if(X[i] == -1){
		int u = (1LL<<i);
		int q = query(u), pc = __builtin_popcount(q);
		if(q == 0) return yes(u);

		if(pc < qnt) X[i] = 1, X[i+1] = 0;
		else X[i] = 0, X[i+1] = 1;
	}

	int x = 0;
	for(int i = 0; i < 60; i++) if(X[i] == 1) x += (1LL<<i);

	cout << "! " << x << endl;
}

int32_t main(){
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
