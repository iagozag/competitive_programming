#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

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

#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 

void no(){ cout << "-1" << endl; }
void yes(int i, char c){ cout << i << " " << c << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, x, y;
char c;

char Le(char cc){
    if(cc == 'N') return 'W';
    if(cc == 'W') return 'S';
    if(cc == 'S') return 'E';
    return 'N';
}


char Ri(char cc){
    if(cc == 'N') return 'E';
    if(cc == 'W') return 'N';
    if(cc == 'S') return 'W';
    return 'S';
}

bool path(string s){
    int xx = 0, yy = 0; char cc = 'N';
    rep(i, 0, n){
        if(s[i] == 'L') cc = Le(cc);
        else if(s[i] == 'R') cc = Ri(cc);
        else if(s[i] == 'F'){
            if(cc == 'N') yy++;
            else if(cc == 'S') yy--;
            else if(cc == 'W') xx--;
            else xx++;
        }
        else{
            if(cc == 'N') yy--;
            else if(cc == 'S') yy++;
            else if(cc == 'W') xx++;
            else xx--;
        }
    }

    return (xx == x and yy == y and cc == c);
}

void solve(){
    cin >> n >> x >> y >> c;
    string s; cin >> s;
    if(path(s)){ cout << 0 << endl; return; }

    string let = "FBLR";
    rep(i, 0, n){
        rep(j, 0, 4) if(s[i] != let[j]){
            string tmp = s; tmp[i] = let[j];
            if(path(tmp)) return yes(i+1, let[j]);
        }
    }

    return no();
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
