#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
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

void solve(){
    string v; cin >> v;

    int m = INF, N = v.size();
    for(int i = 0, j = i+1; i < N-2; i++, j = i+1){
        if(v[i] == v[j]) continue;

        bool aux[3]; aux[0] = aux[1] = aux[2] = 0;
        int cnt = 1; aux[(v[i]-'0')-1] = 1; 
        while(j < N && cnt < 3){
            if(!aux[(v[j]-'0')-1]) cnt++, aux[(v[j]-'0')-1] = 1;
            j++;
        }

        if(cnt == 3) m = min(j-i, m);
        else break;
    }

    cout << (m == INF ? 0 : m) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}


