#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	string s; cin >> s; int n = s.size();
	int Q; cin >> Q;
	vector<int> vis(n); int cnt = 0;
	for(int i = 0; i < n-3; i++){
		string tmp = "";
		for(int j = i; j < i+4; j++) tmp += s[j];
		if(tmp == "1100"){
			cnt++;
			for(int j = i; j < i+4; j++) vis[j] = j-i+1;
		}
	}

	for(int i = 0; i < Q; i++){
		int a; char b; cin >> a >> b; --a;
		if(s[a] == b){ cout << (cnt ? "YES" : "NO") << endl; continue; }

		s[a] = b;
		if(vis[a]){
			int d = a-(vis[a]-1);
			cnt--;
			for(int j = d; j < d+4; j++) vis[j] = 0;
		}

		a = max(0, a-3);
		for(int k = a; k < n-3 and k < a+4; k++){
			string tmp = "";
			for(int j = k; j < k+4; j++) tmp += s[j];
			if(tmp == "1100" and !vis[k]){
				cnt++;
				for(int j = k; j < k+4; j++) vis[j] = j-k+1;
			}
		}

		cout << (cnt ? "YES" : "NO") << endl;
	}
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
