#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

vector<int> p(MAX), e(MAX);

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans *= a;
		a *= a, b >>= 1;
	}
	return ans;
}

void sieve(){
	iota(p.begin(), p.end(), 0), e = vector<int>(MAX, 1);
	for(int i = 2; i < sqrt(MAX)+1; i++) if(p[i] == i) 
		for(int j = i; j < MAX; j += i){
			p[j] = i;
			e[j] = ((j/i)%i == 0 ? e[j/i]+1 : 1);
		}
}

vector<int> fact(int n){
	vector<int> exp;
	while(n != 1){
		exp.emplace_back(e[n]);
		n /= fexp(p[n], e[n]);
	}

	return exp;
}

void solve(){
	int n; cin >> n;
	auto exp = fact(n);
	int ans = 1;
	for(int i = 0; i < exp.size(); i++) ans *= exp[i]+1;
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

	sieve();

    while(ttt--) solve();

    exit(0);
}
