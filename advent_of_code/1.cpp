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
    string st; ll sum = 0;

    map<string, int> mp;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    mp["four"] = 4;
    mp["five"] = 5;
    mp["six"] = 6;
    mp["seven"] = 7;
    mp["eight"] = 8;
    mp["nine"] = 9;

    while(cin >> st){
        string num = "", buffer = "";
        for(int i = 0; i < st.size(); i++){
            if(st[i] >= '0' && st[i] <= '9'){
                num += st[i];
                break;
            }

            buffer += st[i];
            for(auto& x: mp)
                if(buffer.find(x.f) != string::npos){
                    num += to_string(x.s);
                    break;
                }

            if(num.size() == 1) break;
        }

        buffer = "";
        for(int i = st.size()-1; i >= 0; i--){
            if(st[i] >= '0' && st[i] <= '9'){
                num += st[i];
                break;
            }
            
            buffer = st[i] + buffer;
            for(auto& x: mp)
                if(buffer.find(x.f) != string::npos){
                    num += to_string(x.s);
                    break;
                }

            if(num.size() == 2) break;
        }

        sum += stoi(num);
    }

    cout << sum << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

