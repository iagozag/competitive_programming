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
	vector<int> v(n); int ma = 0;
	for(int i = 0; i < n; i++) cin >> v[i], ma = max(ma, v[i]);

	vector<int> even(n/2+1), odd((n+1)/2);
	if(n&1) even.back() = ma;
	else odd.back() = ma;
	if(n&1){
		for(int i = 0; i < n-1; i++){
			int mi = min(i, n-i-2), rest = n-2-2*mi, x = max(v[i], v[i+1]);
			odd[rest/2] = max(odd[rest/2], x);
		}
		for(int i = 1; i < n-1; i++){
			int mi = min(i-1, n-i-2), rest = n-3-2*mi, x = min(v[i], max(v[i-1], v[i+1]));
			even[rest/2] = max(even[rest/2], x);
		}
	} else{
		for(int i = 0; i < n-1; i++){
			int mi = min(i, n-i-2), rest = n-2-2*mi, x = max(v[i], v[i+1]);
			even[rest/2] = max(even[rest/2], x);
		}
		for(int i = 1; i < n-1; i++){
			int mi = min(i-1, n-i-2), rest = n-3-2*mi, x = min(v[i], max(v[i-1], v[i+1]));
			odd[rest/2] = max(odd[rest/2], x);
		}
	}
	
	for(int i = 1; i < (int)even.size(); i++) even[i] = max(even[i], even[i-1]);
	for(int i = 1; i < (int)odd.size(); i++) odd[i] = max(odd[i], odd[i-1]);

	for(int i = 0; i < n; i++){
		if(i&1) cout << odd[i/2] << ' ';
		else cout << even[i/2] << ' ';
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
