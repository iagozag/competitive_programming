#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

string s;

void solve(){
	int n = s.size();
	vector<int> pi(n+1, -1);
	int i = 0, j = -1;
	while(i < n){
		while(j >= 0 and s[i] != s[j]) j = pi[j];
		i++, j++;
		pi[i] = j;
	}

	cout << (pi[n] != 0 and n%(n-pi[n]) == 0 ? n/(n-pi[n]) : 1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(cin >> s and s != ".") solve();

    exit(0);
}
