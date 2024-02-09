#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

const int MAX = 2e5+10;

void solve(){
    int hour, mi; cin >> hour >> mi;
    map<int, int> mp;
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 5;
    mp[5] = 2;
    mp[8] = 8; 

    string s; cin >> s;
    string tmp = ""; tmp += s[0], tmp += s[1];
    int h = stoi(tmp);
    tmp = ""; tmp += s[3], tmp += s[4];
    int m = stoi(tmp);

    while(!mp.count(m%10) or !mp.count((m-m%10)/10) or
          !mp.count(h%10) or !mp.count((h-h%10)/10) or
          (mp[m%10])*10+mp[(m-m%10)/10] >= hour or
          (mp[h%10])*10+mp[(h-h%10)/10] >= mi){
        if((m+1)%mi == 0) h = (h+1)%hour;
        m = (m+1)%mi;
    }

    if(to_string(h).size() == 1) cout << "0" << h << ":";
    else cout << h << ":";
    if(to_string(m).size() == 1) cout << "0" << m << endl;
    else cout << m << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
