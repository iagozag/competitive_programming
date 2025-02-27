#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> lp(MAX), pr;

vector<int> fact(int n){
	vector<int> f;
	while(n != 1){
		f.emplace_back(lp[n]), n /= lp[n];
	}
	return f;
}

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	int ans = 0; vector<int> qnt(n+1);
	for(int i = 0; i < n; i++) qnt[v[i]]++;

	int qpr = 0;
	for(auto p: pr){
		if(p > n) break;
		qpr += qnt[p];
	}

	ans += qpr*(qpr-1)/2;

	for(auto p: pr){
		if(p > n) break;
		ans -= qnt[p]*(qnt[p]-1)/2;
	}

	vector<int> qnt2(n+1);
	for(int i = 0; i < n; i++){
		vector<int> f = fact(v[i]);
		if(f.size() == 2){
			ans += (f[0] != f[1] ? qnt[f[0]]+qnt[f[1]] : qnt[f[0]])+1;
			qnt2[v[i]]++;
		}
	}

	for(auto x: qnt2) ans += x*(x-1)/2;

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	for(int i = 2; i < MAX; i++){
		if(!lp[i]) lp[i] = i, pr.emplace_back(i);
		for(int j = 0; i*pr[j] < MAX; j++){
			lp[i*pr[j]] = pr[j];
			if(pr[j] == lp[i]) break;
		}
	}

    while(ttt--) solve();

    exit(0);
}
