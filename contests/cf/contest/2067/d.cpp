#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int query(int a, int b){
	cout << "? " << a << ' ' << b << endl;
	int q; cin >> q;
	return q;
}

void out(char c){
	cout << "! " << c << endl;
}

void solve(){
	int n; cin >> n;
	set<int> st;
	vector<int> v(n); for(int i = 0; i < n; i++){ cin >> v[i]; st.insert(v[i]); }
	if(st.size() < n){
		for(int i = 1; i <= n; i++) if(!st.count(i)){
			int q = query(i, i == 1 ? 2 : 1);
			return (!q ? out('A') : out('B'));
		}
	}

	int idx1, idx2;
	for(int i = 0; i < n; i++){
		if(v[i] == 1) idx1 = i+1;
		else if(v[i] == n) idx2 = i+1;
	}
	
	int q1 = query(idx1, idx2);
	if(q1 > n-1) return out('B');
	else if(q1 < n-1) return out('A');

	int q2 = query(idx2, idx1);
	return (q1 != q2 ? out('A') : out('B'));

}

int32_t main(){
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
