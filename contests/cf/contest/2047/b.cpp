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
	string s; cin >> s;
	vector<int> v(26); 
	for(auto x: s) v[x-'a']++;

	int idxma = -1, idxmi = -1; 
	for(int i = 0; i < 26; i++) if(v[i]){
		if(idxma == -1 or v[idxma] <= v[i]) idxma = i;
		if(idxmi == -1 or v[idxmi] > v[i]) idxmi = i;
	}

	for(auto& x: s) if(x == (idxmi+'a')){ x = (idxma+'a'); break; }
	cout << s << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
