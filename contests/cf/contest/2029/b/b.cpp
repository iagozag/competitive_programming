#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
string s, r;

void solve(){
	cin >> n >> s >> r;
	stack<int> st; int j = 0;
	for(int i = 0; i < n; i++){
		st.push(s[i]-'0'); bool can = true;
		while(st.size() > 1 and can){
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			if(a^b) st.push(r[j++]-'0');
			else st.push(b), st.push(a), can = false;
		}
	}
	cout << (st.size() == 1 ? "YES" : "NO") << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
