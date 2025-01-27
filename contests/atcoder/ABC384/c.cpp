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
	map<char, int> mp;
	for(int i = 'A'; i <= 'E'; i++) cin >> mp[i];
vector<string> tmp = {
"ABCDE",
"BCDE",
"ACDE",
"ABDE",
"ABCE",
"ABCD",
"CDE",
"BDE",
"ADE",
"BCE",
"ACE",
"BCD",
"ABE",
"ACD",
"ABD",
"ABC",
"DE",
"CE",
"BE",
"CD",
"AE",
"BD",
"AD",
"BC",
"AC",
"AB",
"E",
"D",
"C",
"B",
"A"};

	vector<pair<int, string>> v;
	for(auto x: tmp){
		int sum = 0;
		for(auto y: x) sum += mp[y];
		v.emplace_back(sum, x);
	}

	sort(v.begin(), v.end(), [&](pair<int, string> a, pair<int, string> b){
		if(a.first != b.first) return a.first > b.first;
		return a.second < b.second;
	});
	for(int i = 0; i < 31; i++) cout << v[i].second << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
