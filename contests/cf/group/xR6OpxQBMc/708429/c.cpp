#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	int l = 0, r = 1e9+10, ans = r;
	while(l <= r){
		int m = l+(r-l)/2;

		int cur = -1; bool can = true;
		for(int i = 0; i < n; i++) if(a[i] > m){ 
			if(cur == -1) cur = a[i];
			else{
				if(cur == a[i]) cur = -1;
				else can = false;
			}
		}

		if(cur != -1) can = false;

		for(int i = 0; i < n; i++) if(b[i] > m){ 
			if(cur == -1) cur = b[i];
			else{
				if(cur == b[i]) cur = -1;
				else can = false;
			}
		}

		if(cur != -1) can = false;

		if(can) ans = m, r = m-1;
		else l = m+1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

