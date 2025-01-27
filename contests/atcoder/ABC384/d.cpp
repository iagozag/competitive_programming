#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(){
	cout << "Yes" << endl;
}

bool verify(vector<int>& v, int s){
	int sum = 0, n = v.size();
	set<int> pref = {0}; for(int i = n-1; i >= 0; i--) sum += v[i], pref.insert(sum);

	sum = 0; set<int> st = {0};
	for(int i = 0; i < n; i++){
		sum += v[i];
		if(st.count(sum-s)) return true;
		st.insert(sum);
	}

	s %= sum, sum = 0;
	for(int i = 0; i < n; i++){
		if(pref.count(s-sum)) return true;
		sum += v[i];
	}

	if(pref.count(s-sum)) return true;
	return false;
}

void solve(){
	int n, s, sum = 0; cin >> n >> s;
	vector<int> v(n); for(auto& x: v) cin >> x, sum += x;
	if(verify(v, s)) return yes();
	if(verify(v, s%sum)) return yes();

	cout << "No" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
