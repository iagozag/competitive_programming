#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << "No" << endl;
}

multiset<int> a;
vector<int> b;

bool f(int n){
	if(a.count(n)){
		a.erase(a.find(n));
		return true;
	}
	if(n <= *a.begin()) return false;
	return f(n/2) and f(n/2+(n%2));
}

void solve(){
	int n, m; cin >> n >> m;
	a.clear(); b = vector<int>(m);
	for(int i = 0; i < n; i++){ int x; cin >> x; a.insert(x); }
	for(int i = 0; i < m; i++){ int x; cin >> x; b[i] = x; }
	
	for(int i = 0; i < m; i++){
		if(!f(b[i])) return no();
	}

	cout << (a.empty() ? "Yes" : "No") << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
