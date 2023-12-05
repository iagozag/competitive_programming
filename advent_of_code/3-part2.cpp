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

vector<string> matrix;

bool is_digit(char c){
    return (c >= '0' && c <= '9');
}

bool check(int i, int idx){
    int cnt = 0;
    if(is_digit(matrix[i][idx-1]) || is_digit(matrix[i][idx+1])) cnt++;

    for(int k = idx-1; k <= idx+1; k++){
        if(is_digit(matrix[i-1][k]) || is_digit(matrix[i+1][k]))
            while()cnt++;

    }

    return cnt == 2;
}

void solve(){
    string st; cin >> st;
    int N = st.size();

    matrix.pb(string(N+2, '.'));
    matrix.pb("."+st+".");

    while(cin >> st) matrix.pb("."+st+".");
    matrix.pb(string(N+2, '.'));

    ll sum = 0; N += 2; 

    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            if(matrix[i][j] != '*') continue;

            if(check(i, j)) sum += stol();
        }
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
