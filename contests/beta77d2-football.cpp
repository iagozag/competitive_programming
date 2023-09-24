#include<bits/stdc++.h>
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

void solve(){
    string st; cin >> st;
    int curr = 1;
    for(unsigned i = 1; i < st.size(); i++){
        if(st[i] == st[i-1]) curr++;
        else curr = 1;

        if(curr >= 7) { cout << "YES" << endl; return; }
    }

    cout << "NO" << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}   
