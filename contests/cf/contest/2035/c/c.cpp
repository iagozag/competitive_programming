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
	vector<int> v;
	if(n&1){

	} else{
		int lg2 = __lg(n), ma = (1<<(lg2+1))-1;
		cout << ma << endl;
		set<int> st; v = vector<int>(n); 

		v[n-1] = n, v[n-3] = n^ma, v[n-2] = v[n-3]^1;
		st.insert(n), st.insert(n^ma), st.insert(v[n-2]);

		int last = n-3;
		if(v[n-3]&1) v[n-4] = 1, st.insert(1), last--;

		int k = 1;
		for(int i = 0; i < last; i++){
			while(st.count(k)) k++;
			v[i] = k++;
		}
	}

	for(auto& x: v) cout << x << " ";
	cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
