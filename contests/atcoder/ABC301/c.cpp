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

void solve(){
	string s, t; cin >> s >> t;
	set<int> st; string ss = "atcoder";
	for(auto x: ss) st.insert(x);

	map<char, int> mp, mp2;
	for(auto x: s) mp[x]++;
	for(auto x: t) mp2[x]++;
	
	for(auto [k, v]: mp) if(k != '@' and !st.count(k) and mp2[k] != v) return no();
	for(auto [k, v]: mp2) if(k != '@' and !st.count(k) and mp[k] != v) return no();

	for(auto x: ss){
		if(mp[x] < mp2[x]){
			if(mp['@'] >= mp2[x]-mp[x]) mp['@'] -= mp2[x]-mp[x];
			else return no();
		} else if(mp2[x] < mp[x]){
			if(mp2['@'] >= mp[x]-mp2[x]) mp2['@'] -= mp[x]-mp2[x];
			else return no();
		}
	}

	cout << "Yes" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
