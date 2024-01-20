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

bool cmp(const pair<int,char> &a, const pair<int,char> &b){
    if(a.f != b.f) return a.f > b.f;
    return a.s < b.s;
}

void solve(){
    string st; vector<pair<int,char>> arr(26);
    for(int i = 0; i < 26; i++) arr[i] = {0, (65+i)};
    
    while(getline(cin, st) && !st.empty())
        for(auto& x: st) arr[x-65].f++;

    sort(all(arr), cmp); 

    for(auto& x: arr) cout << x.s << " " << x.f << endl;

}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

