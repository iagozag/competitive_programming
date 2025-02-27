#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

string s; int n;
vector<int> pref;
vector<vector<int>> has;

int inv(int i){
	return n-i-1;
}

vector<int> get(int l, int r){
	vector<int> vr = has[r];
	if(!l) return vr;
	vector<int> vl = has[l-1];
	vector<int> nv(26);
	for(int i = 0; i < 26; i++) nv[i] = vr[i]-vl[i];
	return nv;
}

bool ok(int l, int r){
	return (pref[r]-(l ? pref[l-1] : 0) == r-l+1);
}

bool good(int m){
	for(int r = m-1; r < n; r++){
		int l = r-m+1;
		if(r < n/2){
			if((r < n/2-1 and !ok(r+1, n/2-1)) or (l and !ok(0, l-1))) continue;
			vector<int> ch = get(l, r), need = get(inv(r), inv(l));
			if(ch == need) return true;
		} else if(l < n/2){
			if(r-n/2+1 < n/2-l){
				if((l and !ok(0, l-1))) continue;

				vector<int> ch = get(l, r), need = get(r+1, n-l-1);
				for(int i = 0; i < 26; i++) ch[i] -= need[i];

				bool cant = 0;
				for(int i = 0; i < 26; i++) cant |= (ch[i] < 0 or ch[i]&1);
				if(!cant) return true;
			} else if(r-n/2+1 > n/2-l){
				if((r < n-1 and !ok(r+1, n-1))) continue;

				vector<int> ch = get(l, r), need = get(n-r-1, l-1);
				for(int i = 0; i < 26; i++) ch[i] -= need[i];

				bool cant = 0;
				for(int i = 0; i < 26; i++) cant |= (ch[i] < 0 or ch[i]&1);
				if(!cant) return true;
			} else{
				if(l and !ok(0, l-1)) continue;
				vector<int> ch = get(l, r);
				bool cant = 0;
				for(int i = 0; i < 26; i++) cant |= (ch[i]&1);
				if(!cant) return true;
			}
		} else break;
	}
	
	return false;
}

void solve(){
	cin >> s; n = s.size();
	pref = vector<int>(n), has = vector<vector<int>>(n, vector<int>(26));

	has[0][s[0]-'a'] = 1;
	for(int i = 1; i < n; i++) has[i] = has[i-1], has[i][s[i]-'a']++;

	for(int i = 0; i < n/2; i++) if(s[i] == s[n-i-1]) pref[i] = pref[n-i-1] = 1;

	for(int i = 1; i < n; i++) pref[i] += pref[i-1];

	if(ok(0, n-1)){ cout << 0 << endl; return; }

	int l = 1, r = n, ans = r;
	while(l <= r){
		int m = l+(r-l)/2;
		if(good(m)) ans = m, r = m-1;
		else l = m+1;
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
