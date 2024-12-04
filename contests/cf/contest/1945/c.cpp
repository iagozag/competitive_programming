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
	vector<int> v(n); for(int i = 0; i < n; i++){ char c; cin >> c; v[i] = (c == '1'); }

	vector<int> pref(n); pref[0] = v[0];
	for(int i = 1; i < n; i++) pref[i] = pref[i-1]+v[i];

	int ans = (pref[n-1] >= (n+1)/2 ? 0 : n);
	for(int i = 1; i < n; i++){
		int zero = i-pref[i-1], one = pref[n-1]-pref[i-1];
		if(zero >= (i+1)/2 and one >= (n-i+1)/2 and abs(n-2*ans) > abs(n-2*i)) ans = i;
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
