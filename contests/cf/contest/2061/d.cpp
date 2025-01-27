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
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int i = 0, j = 0;
	while(i < n and j < m){
		if(a[i] == b[j]) i++, j++;
		else{
			if(i < n-1 and abs(a[i]-a[i+1]) <= 1 and a[i]+a[i+1] == b[j]) i += 2, j++;
			else{ cout << "No" << endl; return; }
		}
	}

	if(i == n and j == m) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
