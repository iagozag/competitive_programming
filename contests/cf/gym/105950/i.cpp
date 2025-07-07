#include <bits/stdc++.h>
using namespace std;



int main(){
	int n; cin >> n;
	vector<string> v(n); for(auto& x: v) cin >> x;

	for(int i = 0; i < n; i++){
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
		vector<int> cnt(26);
		for(int j = 0; j < (int)v[i].size(); j++){
			cnt[v[i][j]-'a']++;
			if(cnt[v[i][j]-'a'] > 1){ cout << "NAO" << endl; return 0; }
		}
	}

	vector<vector<int>> mat(26, vector<int>(26));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (int)v[i].size(); j++){
			int a = v[i][j]-'a';
			for(int k = j+1; k < (int)v[i].size(); k++){
				int b = v[i][k]-'a';
				mat[a][b] = 1;
			}
		}
	}

	vector<vector<int>> g(26);
	for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) if(mat[i][j]) g[i].emplace_back(j);

	vector<int> color(26);
	auto cycle = [&](auto&& self, int vv) -> bool{
		color[vv] = 1;
		bool cyc = 0;
		for(auto ve: g[vv]) if(color[ve] != 2){
			if(color[ve] == 1){ cyc = 1; break; }
			else cyc |= self(self, ve);
		}

		color[vv] = 2;
		return cyc;
	};

	for(int i = 0; i < 26; i++) if(color[i] == 0 and cycle(cycle, i)){ cout << "NAO" << endl; return 0; } 

	vector<int> vis(26), ord;
	auto dfs = [&](auto&& self, int vv) -> void {
		vis[vv] = 1;
		for(auto ve: g[vv]) if(!vis[ve]) self(self, ve);
		ord.emplace_back(vv);
	};

	for(int i = 0; i < 26; i++) if(!vis[i]) dfs(dfs, i);
	reverse(ord.begin(), ord.end());

	cout << "SIM" << endl;
	for(auto i: ord) cout << (char)(i+'a');
	cout << endl;

	exit(0);
}
