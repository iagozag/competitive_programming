#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 998244353;

vector<int> factors(MAX);
vector<int> primes;

void sieve(){
	iota(factors.begin(), factors.end(), 0);
	factors[0] = factors[1] = 1;
	for(int i = 2; i < sqrt(MAX)+1; i++) if(factors[i] == i){
		primes.emplace_back(i);
		for(int j = i; j < MAX; j += i) factors[j] = i;
	}
}

vector<int> fact(int n){
	vector<int> ans;
	while(n > 1){
		ans.emplace_back(factors[n]);
		int fa = factors[n];
		while(n > 1 and n%fa == 0) n /= fa;
	}
	return ans;
}

void sum(int& a, int b){
	a += b, a %= MOD;
}

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	vector<int> dp(MAX); dp[v[0]] = 1;
	wq
	
}

int main(){ _
    int ttt = 1; // cin >> ttt;

	sieve();

    while(ttt--) solve();

    exit(0);
}
