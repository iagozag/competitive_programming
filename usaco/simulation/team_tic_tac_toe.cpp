#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	vector<string> v(3); for(int i = 0; i < 3; i++) cin >> v[i];

	set<set<char>> ind, team;

	for(int i = 0; i < 3; i++){
		set<char> st, st2;
		for(int j = 0; j < 3; j++) st.insert(v[i][j]), st2.insert(v[j][i]);
		if(st.size() == 1) ind.insert(st);
		else if(st.size() == 2) team.insert(st);
		if(st2.size() == 1) ind.insert(st2);
		else if(st2.size() == 2) team.insert(st2);
	}
	set<char> st;
	for(int i = 0; i < 3; i++) st.insert(v[i][i]);
	if(st.size() == 1) ind.insert(st);
	else if(st.size() == 2) team.insert(st);
	st.clear(), st.insert(v[2][0]), st.insert(v[1][1]), st.insert(v[0][2]);
	if(st.size() == 1) ind.insert(st);
	else if(st.size() == 2) team.insert(st);

	cout << ind.size() << endl << team.size() << endl;
}

int main(){ _
    if (fopen("tttt.in", "r")) {
		freopen("tttt.in", "r", stdin);
		freopen("tttt.out", "w", stdout);
	}

    int t = 1;

    while(t--) solve();

    exit(0);
}
