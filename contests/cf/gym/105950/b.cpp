#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	vector<vector<int>> pos(26);
	for(int i = 0; i < n; i++) pos[s[i]-'a'].emplace_back(i);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < (s[i]-'a'); j++) if(!pos[j].empty() and pos[j].back() > i){
			swap(s[i], s[pos[j].back()]);
			cout << s << endl;
			return 0;
		}
	}

	cout << s << endl;

	exit(0);
}
