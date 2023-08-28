#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    if(s == "()"){
        cout << "NO" << endl;
        return;
    }

    bool r = true;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]) 
            r = false;
    }

    cout << "YES" << endl;
    if(r){
        for(int i = 0; i < s.size(); i++) cout << "(";
        for(int i = 0; i < s.size(); i++) cout << ")";
    }
    else
        for(int i = 0; i < s.size(); i++) cout << "()";

    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
