#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> pi(string s){
    int n = s.size(); vector<int> p(n);
    for(int i = 1, j = 0; i < n; i++){
        while(j and s[i] != s[j]) j = p[j-1];
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

void solve(){
    string t, s; cin >> t >> s; int m = t.size(), n = s.size();
    vector<int> p = pi(s+'$'), ans;
    for(int i = 0, j = 0; i < m; i++){
        while(j and t[i] != s[j]) j = p[j-1];
        if(t[i] == s[j]) j++;
        if(j == n) ans.emplace_back(i-j+1);
    }
    if(ans.size() == 0){ cout << "Not Found" << endl; return; }
    cout << ans.size() << endl;
    for(auto x: ans) cout << x+1 << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--){ solve(); if(ttt) cout << endl; }

    exit(0);
}
