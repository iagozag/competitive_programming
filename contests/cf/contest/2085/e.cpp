#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(int k){
	cout << k << endl;
}

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto& x: a) cin >> x;
	set<int> st;
	for(auto& x: b) cin >> x, st.insert(x);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if(st.size() < n){
		vector<int> diff;
		for(int i = 1; i < n; i++) diff.emplace_back(a[i]-a[i-1]);

		vector<int> ms;
		for(auto x: diff){
			for(int i = 0; i < n; i++)
				ms.emplace_back(a[i]%x);
			sort(ms.begin(), ms.end());
			if(ms == b) return yes(x);
			ms.clear();
		}
	}
	else if(a == b) return yes(1e9);

	cout << -1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
