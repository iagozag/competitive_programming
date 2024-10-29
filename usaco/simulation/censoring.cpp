#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	string s, p; cin >> s >> p; int m = p.size();
	vector<int> v(s.size());
	
	for(int i = 0; i < s.size(); i++){
		if(i and s[i] == p[v[i-1]]) v[i] = v[i-1]+1;
		else if(s[i] == p[0]) v[i] = 1;

		if(v[i] == m) s.erase(i-m+1, m), v.erase(v.begin()+i-m+1, v.begin()+i+1), i -= m;	
	}

	cout << s << endl;
}

int main(){ _
    if (fopen("censor.in", "r")) {
		freopen("censor.in", "r", stdin);
		freopen("censor.out", "w", stdout);
	}

    int t = 1;

    while(t--) solve();

    exit(0);
}
