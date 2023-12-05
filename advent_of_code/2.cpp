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

    map<string,int> min;
    min["red"] = -1;
    min["blue"] = -1;
    min["green"] = -1;

    while(getline(cin, st)){
        st += ';';
        int id, begin; string buffer = "";

        for(size_t i = 5; i < st.size(); i++){
            if(st[i] == ':') { id = stoi(buffer), begin = i+2; break; }

            buffer += st[i];
        }

        map<string,int> mp;
        for(int i = begin; i < st.size(); i++){
            if(st[i] == ',' || st[i] == ' ') continue;
            if(st[i] == ';'){
                for(auto& x: mp)
                    if(min[x.f] < x.s) min[x.f] = x.s;

                mp.clear();

                if(i == st.size()-1) break;
                i += 2;
            }

            buffer = ""; int tmp = 0;
            while(st[i] >= '0' && st[i] <= '9') buffer += st[i], i++;
            tmp += stoi(buffer), i++;

            buffer = "";
            while(i < st.size()){
                buffer += st[i];
                if(st[i+1] == ',' || st[i+1] == ';') break;

                i++;
            }
            
            mp[buffer] += tmp;
        }

        ll power = 1;
        for(auto& x: min) power *= x.s;

        sum += power;

        min["red"] = -1;
        min["blue"] = -1;
        min["green"] = -1;
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

