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
	vector<int> v(n); for(auto& x: v) cin >> x;
	set<int> ans;

	int idx = -1;
	for(int i = 0; i < n; i++) if(abs(v[i]) != 1) idx = i;

	if(idx == -1){
		int suma = 0, sumi = 0, mi = 0, ma = 0;
		for(int i = 0; i < n; i++){
			suma += v[i], sumi += v[i];
			ma = max(ma, suma), mi = min(mi, sumi);
			if(suma < 0) suma = 0;
			if(sumi > 0) sumi = 0;
		}
		cout << ma-mi+1 << endl;
		for(int i = mi; i <= ma; i++) cout << i << ' ';
		cout << endl;
		return;
	}

	int suma = 0, sumi = 0, mi = 0, ma = 0;
	for(int i = 0; i < idx; i++){
		suma += v[i], sumi += v[i];
		ma = max(ma, suma), mi = min(mi, sumi);
		if(suma < 0) suma = 0;
		if(sumi > 0) sumi = 0;
	}
	for(int i = mi; i <= ma; i++) ans.insert(i);

	suma = 0, sumi = 0, mi = 0, ma = 0;
	for(int i = n-1; i > idx; i--){
		suma += v[i], sumi += v[i];
		ma = max(ma, suma), mi = min(mi, sumi);
		if(suma < 0) suma = 0;
		if(sumi > 0) sumi = 0;
	}
	for(int i = mi; i <= ma; i++) ans.insert(i);

	ans.insert(v[idx]);

	mi = 0, ma = 0; int sum = 0;
	for(int i = idx-1; i >= 0; i--) sum += v[i], mi = min(mi, sum), ma = max(ma, sum);

	int mi2 = 0, ma2 = 0; sum = 0;
	for(int i = idx+1; i < n; i++) sum += v[i], mi2 = min(mi2, sum), ma2 = max(ma2, sum);

	mi += mi2, ma += ma2;
	for(int i = v[idx]+mi; i <= v[idx]+ma; i++) ans.insert(i);
	
	cout << ans.size() << endl;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
