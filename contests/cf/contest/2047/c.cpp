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
	vector<int> a(n), b(n); multiset<pair<int, int>, greater<pair<int, int>>> st;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		cin >> b[i];
		if(b[i] > a[i]) swap(a[i], b[i]);
	}
	
	for(int i = 0; i < n; i++) st.insert({a[i], b[i]});

	int ans = -INF;
	for(int c = 0; c < n; c++){
		int sum = a[c]+b[c];
		st.erase(st.find({a[c], b[c]}));
		int cnt = 0;
		for(auto x: st){
			if(cnt >= n-1) break;
			sum += x.first, cnt++;
		}
		st.insert({a[c], b[c]});
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
