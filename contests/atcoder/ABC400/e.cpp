#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

vector<int> lp(MAX), pr;
vector<int> num;

void sieve(){
	for(int i = 2; i < MAX; i++){
		if(lp[i] == 0){
			lp[i] = i;
			pr.emplace_back(i);
		}
		for(int j = 0; i*pr[j] < MAX; j++){
			lp[i*pr[j]] = pr[j];
			if(pr[j] == lp[i]) break;
		}
	}
}

set<int> fact(int n){
	set<int> ans;
	
	while(n != 1){
		ans.insert(lp[n]), n /= lp[n];
	}	

	return ans;
}

void solve(){
	int x; cin >> x;
	int ub = upper_bound(num.begin(), num.end(), x)-num.begin();
	cout << num[ub-1] << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	sieve();

	for(int i = 1; i < MAX; i++){
		set<int> f = fact(i);
		if(f.size() == 2) num.emplace_back(i*i);
	}

    while(ttt--) solve();

    exit(0);
}
