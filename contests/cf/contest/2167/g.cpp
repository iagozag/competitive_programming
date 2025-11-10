#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 8001, MOD = 1e9+7;


void solve(){
	int n;cin >> n;
	
	int v[n], c[n]; set<int> st;
	for(int i = 0; i < n; i++) cin >> v[i], st.insert(v[i]);
	for(int i = 0; i < n; i++) cin >> c[i];

	int k = 0; map<int, int> mp;
	for(auto x: st) mp[x] = k++;

	for(int i = 0; i < n; i++) v[i] = mp[v[i]];

	vector<int> memo(k, c[0]);
	for(int i = v[0]; i < k; i++) memo[i] = 0;

	for(int i = 1; i < n; i++){
		vector<int> tmp(k, LINF);

		for(int j = 0; j < k; j++){
			tmp[j] = memo[j]+c[i]*(j != v[i]);

			if(j) tmp[j] = min(tmp[j], tmp[j-1]);
		}

		swap(memo, tmp);
	}

	int mi = LINF;
	for(int i = 0; i < k; i++) mi = min(mi, memo[i]);

	cout << mi << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
