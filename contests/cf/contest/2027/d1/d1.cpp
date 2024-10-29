#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<ll> a(n), b(m+1); multiset<ll> st;
	for(int i = 0; i < n; i++) cin >> a[i], st.insert(a[i]);
	for(int i = 0; i < m; i++) cin >> b[i];

	if(b[0] < *max_element(a.begin(), a.end())){ cout << -1 << endl; return; }

	int i = 0, j = 0; ll ans = 0, sum = 0;
	while(i < n){
		while(i < n and sum >= a[i]) sum -= a[i], st.erase(st.find(a[i])), i++;
		sum = 0;

		ll now = b[j], nxt = b[j+1];
		if(st.upper_bound(nxt) != st.end()) ans += m-j-1, sum += now;
		else j++;
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
