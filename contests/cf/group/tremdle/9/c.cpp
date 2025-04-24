#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int query(int i, int j, int k){
	cout << "? " << i << ' ' << j << ' ' << k << endl;
	cout.flush();

	string s; cin >> s;
	if(s == "-1") exit(0);

	return s == "Yes";
}

void solve(){
	int n; cin >> n;
	vector<int> ans(n);

	int idx = 0;
	for(int i = 1; i < n; i++){
		int q = query(i+1, i+1, idx+1);
		if(!q) idx = i;
	}

	ans[idx] = 1;

	vector<int> v;
	for(int i = 0; i < n; i++) if(i != idx) v.emplace_back(i);

	stable_sort(v.begin(), v.end(), [&](const int a, const int b){
		return !query(idx+1, a+1, b+1);
	});

	for(int i = 0; i < n-1; i++) ans[v[i]] = i+2;

	cout << "! ";
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
