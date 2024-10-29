#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> ov(n); for(auto& x: ov) cin >> x;
	vector<pair<int, int>> v((n+1)/2); 
	for(int i = 0; i < (n+1)/2; i++){
		v[i] = {ov[i], ov[n-i-1]};
	}

	for(int i = 1; i < (n+1)/2; i++){
		if(v[i].first == v[i-1].first or v[i].second == v[i-1].second) swap(v[i].first, v[i].second);
	}
	
	vector<int> nv(n);
	for(int i = 0; i < v.size(); i++){
		nv[i] = v[i].first, nv[n-i-1] = v[i].second;
	}
	int ans = 0;
	for(int i = 0; i < n-1; i++) if(nv[i] == nv[i+1]) ans++;
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();


    exit(0);
}
